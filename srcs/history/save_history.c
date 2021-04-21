/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:36:46 by ndemont           #+#    #+#             */
/*   Updated: 2021/04/26 16:19:22 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_history(char *line, t_big *datas)
{
	t_history *test;

	update_history_list(datas->history, line, 1);
	test = *datas->history;
	while(test)
	{
		if (test->command)
			printf("[%s]\n", test->command);
		test = test->next;
	}
}