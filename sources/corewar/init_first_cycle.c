/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:26:07 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 18:26:10 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_init_first_cycle(t_war *war)
{
	t_crg	*tmp;
	int		opp;

	tmp = war->top;
	while (tmp)
	{
		opp = (int)(war->arena[tmp->pos].code);
		if (opp > 0 && opp < 17)
		{
			tmp->to_do = war->opp[opp].cycle;
			tmp->op = opp;
		}
		else
		{
			tmp->to_do = 0;
			tmp->op = -1;
		}
		war->arena[tmp->pos].crg_clr = tmp->player;
		war->arena[tmp->pos].busy = 1;
		tmp = tmp->next;
	}
}
