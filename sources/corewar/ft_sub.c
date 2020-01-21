/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:12:19 by pnita             #+#    #+#             */
/*   Updated: 2019/11/16 15:43:53 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_sub(t_war *war, t_crg *crg)
{
	int pos;
	int	reg1;
	int	reg2;
	int	reg3;

	pos = crg->pos + 2;
	reg1 = war->arena[GG(pos)].code;
	pos += 1;
	reg2 = war->arena[GG(pos)].code;
	pos += 1;
	reg3 = war->arena[GG(pos)].code;
	if (reg1 >= 1 && reg1 <= 16 && reg2 >= 1
			&& reg2 <= 16 && reg3 >= 1 && reg3 <= 16)
	{
		crg->reg[reg3] = crg->reg[reg1] - crg->reg[reg2];
		if (crg->reg[reg3] == 0)
		{
			crg->carry = 1;
		}
		else
		{
			crg->carry = 0;
		}
	}
	ft_move_crg(war, crg, 5);
}
