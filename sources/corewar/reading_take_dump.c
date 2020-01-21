/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_take_dump.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:25:55 by pnita             #+#    #+#             */
/*   Updated: 2019/12/08 22:25:59 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_take_dump(t_war *war, int index)
{
	unsigned int	res;
	int				i;
	char			*line;

	i = 0;
	res = 0;
	line = war->argv[index];
	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] <= 57)
		{
			res = res * 10 + line[i] - 48;
		}
		else
		{
			ft_free_exit(war, 10);
		}
		i++;
	}
	if (i > 10 || res > 2147483647)
	{
		ft_free_exit(war, 10);
	}
	war->dump_cycle = (int)res;
}
