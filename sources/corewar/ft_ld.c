/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:36:34 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:59:10 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_ld_dir(t_war *war, t_crg *crg)
{
	int arg;
	int pos;
	int reg;

	pos = crg->pos + 2;
	arg = get_arg_dir(war, pos, 4);
	reg = war->arena[GG(pos + 4)].code;
	if (reg >= 1 && reg <= 16)
	{
		if (arg == 0)
		{
			crg->carry = 1;
		}
		else
		{
			crg->carry = 0;
		}
		crg->reg[reg] = arg;
	}
}

void	ft_ld_ind(t_war *war, t_crg *crg, int cases)
{
	int arg1;
	int arg2;
	int pos;
	int reg;

	pos = crg->pos + 2;
	arg1 = get_arg_ind(war, pos);
	reg = war->arena[GG(pos + 2)].code;
	if (cases == 0)
		pos = crg->pos + arg1 % IDX_MOD;
	else
		pos = crg->pos + arg1;
	arg2 = get_arg_dir(war, pos, 4);
	if (reg >= 1 && reg <= 16)
	{
		crg->reg[reg] = arg2;
		if (arg2 == 0)
			crg->carry = 1;
		else
			crg->carry = 0;
	}
}

void	ft_ld(t_war *war, t_crg *crg, int cases)
{
	if (crg->args[0] == 5)
	{
		ft_ld_dir(war, crg);
		ft_move_crg(war, crg, 7);
	}
	else
	{
		ft_ld_ind(war, crg, cases);
		ft_move_crg(war, crg, 5);
	}
}
