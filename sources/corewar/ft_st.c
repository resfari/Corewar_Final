/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:26:20 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 17:00:17 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_st_reg(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int new_reg;

	pos = crg->pos + 2;
	reg = war->arena[GG(pos)].code;
	if (reg >= 1 && reg <= 16)
	{
		pos += 1;
		new_reg = war->arena[GG(pos)].code;
		if (new_reg >= 1 && new_reg <= 16)
		{
			crg->reg[new_reg] = crg->reg[reg];
		}
	}
}

void	ft_st_ind(t_war *war, t_crg *crg)
{
	int pos;
	int reg;
	int	ind;
	int i;

	pos = crg->pos + 2;
	ind = 0;
	reg = get_arg_reg(war, pos);
	ind = get_arg_ind(war, crg->pos + 3);
	ind = ind % IDX_MOD;
	pos = crg->pos + ind;
	if (reg >= 1 && reg <= 16)
	{
		i = 0;
		while (i < 4)
		{
			war->arena[GG(pos + i)].code =
					(crg->reg[reg] >> (8 * (3 - i)));
			war->arena[GG(pos + i)].color = crg->player;
			i++;
		}
	}
}

void	ft_st(t_war *war, t_crg *crg)
{
	if (crg->args[1] == 3)
	{
		ft_st_reg(war, crg);
		ft_move_crg(war, crg, 4);
	}
	else
	{
		ft_st_ind(war, crg);
		ft_move_crg(war, crg, 5);
	}
}
