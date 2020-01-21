/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:17:38 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 17:01:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_zjmp(t_war *war, t_crg *crg)
{
	int arg;
	int pos;

	if (crg->carry == 1)
	{
		pos = crg->pos + 1;
		arg = get_arg_dir(war, pos, 2);
		ft_move_crg(war, crg, arg % IDX_MOD);
	}
	else
	{
		ft_move_crg(war, crg, 3);
	}
}
