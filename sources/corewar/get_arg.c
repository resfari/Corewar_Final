/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:00:07 by pnita             #+#    #+#             */
/*   Updated: 2019/12/06 17:01:16 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

int	get_arg_reg(t_war *war, int pos)
{
	return ((int)(war->arena[GG(pos)].code));
}

int	get_arg_dir(t_war *war, int pos, int size)
{
	unsigned short	dir1;
	unsigned int	dir2;

	if (size == 2)
	{
		dir1 = (war->arena[GG(pos)].code << 8)
				| (war->arena[GG(pos + 1)].code);
		return ((short)dir1);
	}
	dir2 = (war->arena[GG(pos)].code << 24)
			| (war->arena[GG(pos + 1)].code << 16)
			| (war->arena[GG(pos + 2)].code << 8)
			| war->arena[GG(pos + 3)].code;
	return ((int)dir2);
}

int	get_arg_ind(t_war *war, int pos)
{
	unsigned short ind;

	ind = (war->arena[GG(pos)].code << 8)
			| (war->arena[GG(pos + 1)].code);
	return ((short)ind);
}
