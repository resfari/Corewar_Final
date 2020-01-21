/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:18:15 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:47:33 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_check_name(t_war *war, int num)
{
	int i;
	int j;

	i = 0;
	j = 4;
	while (i < PROG_NAME_LENGTH)
	{
		war->player[num].name[i] = war->player[num].text[j];
		i++;
		j++;
	}
	war->player[num].name[i] = '\0';
}

void	ft_check_comment(t_war *war, int num)
{
	int i;
	int j;

	i = 0;
	j = 12 + PROG_NAME_LENGTH;
	while (i < COMMENT_LENGTH)
	{
		war->player[num].comment[i] = war->player[num].text[j];
		i++;
		j++;
	}
	war->player[num].comment[i] = '\0';
}
