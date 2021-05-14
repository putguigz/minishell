/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:19:05 by ndemont           #+#    #+#             */
/*   Updated: 2021/05/11 16:39:09 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_node **tokens)
{
	int i;
	int j;

	i = 0;
	if (tokens)
	{
		while (tokens[i])
		{
			if (tokens[i]->input)
				free(tokens[i]->input);
			if (tokens[i]->arg)
			{
				j = 0;
				while (tokens[i]->arg[j])
				{
					free(tokens[i]->arg[j]);
					tokens[i]->arg[j] = 0;
					j++;
				}
				free(tokens[i]->arg);
			}
			if (tokens[i]->builtin)
				free(tokens[i]->builtin);
			if (tokens[i]->command)
				free(tokens[i]->command);
			free(tokens[i]);
			i++;
		}
		free(tokens);
		tokens = 0;
	}
}

void	free_list(t_list **list)
{
	t_list *tmp;
	t_list *elem;

	if (list)
	{
		elem = *list;
		while (elem)
		{
			if (elem->content)
			{
				if (((t_var *)elem->content)->var)
				{
					free(((t_var *)elem->content)->var);
					((t_var *)elem->content)->var = 0;
				}
				if (((t_var *)elem->content)->value)
				{
					free(((t_var *)elem->content)->value);
					((t_var *)elem->content)->value = 0;
				}
				free(elem->content);
				elem->content = 0;
			}
			tmp = elem;
			elem = elem->next;
			free(tmp);
			tmp = 0;
		}
		free(list);
		list = 0;
	}
}

void	free_history(t_history **list)
{
	t_history *tmp;
	t_history *del;

	tmp = *list;
	while (tmp)
	{
		del = tmp;
		if (del->command)
			free(del->command);
		tmp = tmp->next;
		free(del);
	}
	if (*list)
		free(list);
}

void	free_arg(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		arg[i] = 0;
		i++;
	}
}


void	free_tree(t_node *root)
{
	if (root->left)
	{
		free_tree(root->left);
	}
	if (root->right)
	{
		free_tree(root->right);
	}
	if (root->input)
	{
		free(root->input);
		root->input = 0;
	}
	if (root->arg)
	{
		free_arg(root->arg);
		free(root->arg);
		root->arg = 0;
	}
	if (root->builtin)
	{
		free(root->builtin);
		root->builtin = 0;
	}
	if (root->command)
	{
		free(root->command);
		root->command = 0;
	}
	if (root)
	{
		free(root);
		root = 0;
	}
}

void	clean_datas(t_big *datas)
{
	free_double(datas->redirection_arg);
	if (datas && datas->file_name)
		free(datas->file_name);
	free_tree(datas->root);
	if (datas->input)
		free(datas->input);
	if (datas->browse)
		free(datas->browse);
}

int		free_datas(t_big *datas)
{
	if (datas)
	{
		if (datas->redirection_arg)
			free_double(datas->redirection_arg);
		if (datas && datas->file_name)
			free(datas->file_name);
		if (datas->env)
			free_list(datas->env);
		if (datas->export)
			free_list(datas->export);
		if (datas->hidden)
			free_list(datas->hidden);
		if (datas->history)
			free_history(datas->history);
		if (datas->root)
			free_tree(datas->root);
		if (datas->input)
			free(datas->input);
		if (datas->browse)
			free(datas->browse);
	}
	return (1);
}
