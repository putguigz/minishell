/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:02:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/29 16:05:42 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **buildin_list(void)
{
	char **list[8] = {"echo", "export", "env", "cd", "pwd", "unset", "exit", "$?"};

	return (list);
}