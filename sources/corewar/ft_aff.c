/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:39:00 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:58:12 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_aff(t_war *war, t_crg *crg)
{
	int c;
	int pos;
	int reg;

	pos = GG(crg->pos + 2);
	reg = get_arg_reg(war, pos);
	if (reg >= 1 && reg <= 16)
	{
		c = crg->reg[reg];
		if (war->aff == 1)
			ft_printf("Aff: %c\n", (char)c);
	}
	ft_move_crg(war, crg, 3);
}
