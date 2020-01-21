/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:38:07 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 17:00:50 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_move_sti_reg_error(t_war *war, t_crg *crg)
{
	int res;

	res = 3;
	if (crg->args[1] == 3)
		res += 1;
	else
		res += 2;
	if (crg->args[2] == 3)
		res += 1;
	else
		res += 2;
	ft_move_crg(war, crg, res);
}

int		ft_sti_do_with_arg1(t_war *war, t_crg *crg, int *pos)
{
	if (crg->args[1] == 3)
	{
		war->arg2 = get_arg_reg(war, *pos);
		if (war->arg2 >= 1 && war->arg2 <= 16)
			war->arg2 = crg->reg[war->arg2];
		else
		{
			ft_move_sti_reg_error(war, crg);
			return (0);
		}
		*pos += 1;
	}
	else if (crg->args[1] == 5)
	{
		war->arg2 = get_arg_dir(war, *pos, 2);
		*pos += 2;
	}
	else
	{
		war->arg2 = get_arg_ind(war, *pos);
		war->arg2 = get_arg_dir(war, crg->pos + war->arg2 % IDX_MOD, 4);
		*pos += 2;
	}
	return (1);
}

int		ft_sti_do_with_arg2(t_war *war, t_crg *crg, int *pos)
{
	if (crg->args[2] == 3)
	{
		war->arg3 = get_arg_reg(war, *pos);
		if (war->arg3 >= 1 && war->arg3 <= 16)
			war->arg3 = crg->reg[war->arg3];
		else
		{
			ft_move_sti_reg_error(war, crg);
			return (0);
		}
		*pos += 1;
	}
	else
	{
		war->arg3 = get_arg_dir(war, *pos, 2);
		*pos += 2;
	}
	return (1);
}

void	ft_sti(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int i;
	int x;

	pos = crg->pos + 2;
	reg = get_arg_reg(war, pos);
	if (reg >= 1 && reg <= 16)
	{
		pos += 1;
		if (!ft_sti_do_with_arg1(war, crg, &pos)
				|| !ft_sti_do_with_arg2(war, crg, &pos))
			return ;
		i = 0;
		while (i < 4)
		{
			x = crg->pos + (war->arg2 + war->arg3) % IDX_MOD + i;
			war->arena[GG(x)].code = (crg->reg[reg] >> (8 * (3 - i)));
			war->arena[GG(x)].color = crg->player;
			i++;
		}
		ft_move_crg(war, crg, pos - crg->pos);
	}
	else
		ft_move_sti_reg_error(war, crg);
}
