/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:29 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/17 16:35:39 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_reserve_num_for_players(t_war *war)
{
	int i;

	i = 1;
	while (i < 5)
	{
		war->reserved_num[i] = 0;
		war->reserved_wo_n[i] = 0;
		i++;
	}
}

void	ft_init_arena(t_war *war)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		war->arena[i].code = 0;
		i++;
	}
}

void	ft_init_main(t_war *war, char **argv, int argc)
{
	war->argv = argv;
	war->argc = argc;
	war->to_die = CYCLE_TO_DIE;
	war->speed = 1;
	ft_init_opp(war);
}
