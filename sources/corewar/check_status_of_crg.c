/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_of_crg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:30:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:55:20 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_check_one_crg_if_moved(t_war *war, t_crg *crg)
{
	crg->op = get_arg_reg(war, crg->pos);
	if (crg->op >= 1 && crg->op <= 16)
	{
		crg->to_do = war->opp[crg->op].cycle - 2;
		crg->moved = 0;
	}
	else
	{
		crg->to_do = 0;
		crg->op = 0;
		ft_move_crg(war, crg, 1);
		crg->moved = 1;
	}
}

void	ft_check_one_crg(t_war *war, t_crg *crg)
{
	if (crg->to_do > 0)
		crg->to_do--;
	else
	{
		if (crg->moved == 1)
			ft_check_one_crg_if_moved(war, crg);
		else if (crg->to_do == 0)
		{
			if (crg->op == 1 || crg->op == 9
					|| crg->op == 12 || crg->op == 15 ||
			ft_check_argument(war, crg, crg->op) == 1)
				ft_detect_operation(crg->op, war, crg);
			else
				ft_move_crg(war, crg, crg->bytes_to_go);
			crg->moved = 1;
		}
	}
}

void	ft_check_status_of_crg(t_war *war, t_crg *crg)
{
	t_crg *help;

	(void)crg;
	help = war->top;
	while (help)
	{
		if (help->die == 0)
		{
			ft_check_one_crg(war, help);
		}
		help = help->next;
	}
}
