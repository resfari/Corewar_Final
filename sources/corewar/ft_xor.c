/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:11:09 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 17:00:59 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_xor_do_with_arg1(t_war *war, t_crg *crg,
		int *pos, int *bit_xor_arg1_2)
{
	int tmp_arg;
	int new_pos;

	if (crg->args[1] == 3)
	{
		tmp_arg = war->arena[GG(*pos)].code;
		if (tmp_arg >= 1 && tmp_arg <= 16)
			*bit_xor_arg1_2 = *bit_xor_arg1_2 ^ crg->reg[tmp_arg];
		*pos += 1;
	}
	else if (crg->args[1] == 5)
	{
		tmp_arg = get_arg_dir(war, *pos, 4);
		*bit_xor_arg1_2 = *bit_xor_arg1_2 ^ tmp_arg;
		*pos += 4;
	}
	else
	{
		tmp_arg = get_arg_ind(war, *pos);
		new_pos = crg->pos + tmp_arg % IDX_MOD;
		tmp_arg = get_arg_dir(war, new_pos, 4);
		*bit_xor_arg1_2 = *bit_xor_arg1_2 ^ tmp_arg;
		*pos += 2;
	}
}

void	ft_xor(t_war *war, t_crg *crg)
{
	int pos;
	int tmp_arg;
	int bit_xor_arg1_2;

	pos = crg->pos + 2;
	bit_xor_arg1_2 = 0;
	ft_and_or_xor_do_with_arg0(war, crg, &pos, &bit_xor_arg1_2);
	ft_xor_do_with_arg1(war, crg, &pos, &bit_xor_arg1_2);
	tmp_arg = war->arena[GG(pos)].code;
	if (tmp_arg >= 1 && tmp_arg <= 16)
	{
		crg->reg[tmp_arg] = bit_xor_arg1_2;
		if (crg->reg[tmp_arg] == 0)
			crg->carry = 1;
		else
			crg->carry = 0;
	}
	ft_andor_calc_move(war, crg);
}
