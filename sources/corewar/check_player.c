/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:54:01 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

int		ft_check_free_num(t_war *war, int num)
{
	if (war->reserved_num[num] != 0)
		return (0);
	else
	{
		war->reserved_num[num] = num;
		war->numb_players++;
	}
	return (1);
}

int		ft_check_valid_num(t_war *war, char *line)
{
	int len;

	(void)war;
	len = ft_strlen(line);
	if (len != 1)
		return (0);
	if (line[0] < '1' || line[0] > '4')
		return (0);
	else
		return (line[0] - 48);
}

void	ft_full_reserved(t_war *war)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		if (war->reserved_num[i] == 0)
		{
			if (war->reserved_wo_n[j] != 0)
			{
				war->player[i].path = war->argv[war->reserved_wo_n[j]];
				war->reserved_num[i] = i;
				j++;
			}
			else
			{
				return ;
			}
		}
		i++;
	}
}

int		ft_check_order_amount_players(t_war *war)
{
	int i;

	i = 1;
	if (war->numb_players < 1 || war->numb_players > 4)
		return (0);
	ft_full_reserved(war);
	while (i <= war->numb_players)
	{
		if (war->reserved_num[i] == 0
				|| war->reserved_num[i] > war->numb_players)
			return (0);
		i++;
	}
	return (1);
}
