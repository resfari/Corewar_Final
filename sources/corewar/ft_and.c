/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:17:12 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 16:58:24 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_andor_calc_move(t_war *war, t_crg *crg)
{
	int res;

	res = 3;
	if (crg->args[0] == 3)
		res += 1;
	else if (crg->args[0] == 5)
		res += 4;
	else
		res += 2;
	if (crg->args[1] == 3)
		res += 1;
	else if (crg->args[1] == 5)
		res += 4;
	else
		res += 2;
	ft_move_crg(war, crg, res);
}

void	ft_and_or_xor_do_with_arg0(t_war *war, t_crg *crg,
		int *pos, int *bit_val)
{
	int tmp_arg;
	int new_pos;

	if (crg->args[0] == 3)
	{
		tmp_arg = war->arena[GG(*pos)].code;
		if (tmp_arg >= 1 && tmp_arg <= 16)
			*bit_val = crg->reg[tmp_arg];
		*pos += 1;
	}
	else if (crg->args[0] == 5)
	{
		tmp_arg = get_arg_dir(war, *pos, 4);
		*bit_val = tmp_arg;
		*pos += 4;
	}
	else
	{
		tmp_arg = get_arg_ind(war, *pos);
		new_pos = crg->pos + tmp_arg % IDX_MOD;
		tmp_arg = get_arg_dir(war, new_pos, 4);
		*bit_val = tmp_arg;
		pos += 2;
	}
}

void	ft_and_do_with_arg1(t_war *war, t_crg *crg,
		int *pos, int *bit_and_arg1_2)
{
	int tmp_arg;
	int new_pos;

	if (crg->args[1] == 3)
	{
		tmp_arg = war->arena[GG(*pos)].code;
		if (tmp_arg >= 1 && tmp_arg <= 16)
			*bit_and_arg1_2 = *bit_and_arg1_2 & crg->reg[tmp_arg];
		*pos += 1;
	}
	else if (crg->args[1] == 5)
	{
		tmp_arg = get_arg_dir(war, *pos, 4);
		*bit_and_arg1_2 = *bit_and_arg1_2 & tmp_arg;
		*pos += 4;
	}
	else
	{
		tmp_arg = get_arg_ind(war, *pos);
		new_pos = crg->pos + tmp_arg % IDX_MOD;
		tmp_arg = get_arg_dir(war, new_pos, 4);
		*bit_and_arg1_2 = *bit_and_arg1_2 & tmp_arg;
		*pos += 2;
	}
}

void	ft_and(t_war *war, t_crg *crg)
{
	int pos;
	int tmp_arg;
	int bit_and_arg1_2;

	pos = crg->pos + 2;
	bit_and_arg1_2 = 0;
	ft_and_or_xor_do_with_arg0(war, crg, &pos, &bit_and_arg1_2);
	ft_and_do_with_arg1(war, crg, &pos, &bit_and_arg1_2);
	tmp_arg = war->arena[GG(pos)].code;
	if (tmp_arg >= 1 && tmp_arg <= 16)
	{
		crg->reg[tmp_arg] = bit_and_arg1_2;
		if (crg->reg[tmp_arg] == 0)
			crg->carry = 1;
		else
			crg->carry = 0;
	}
	ft_andor_calc_move(war, crg);
}
