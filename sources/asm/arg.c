/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:00:30 by pnita             #+#    #+#             */
/*   Updated: 2019/12/12 19:00:32 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	fill_arg(t_arg *arg, int val, int size, int code)
{
	arg->size = size;
	arg->code = code;
	if (size == 1)
	{
		arg->bytes[0] = val;
	}
	else if (size == 2)
	{
		arg->bytes[1] = val;
		arg->bytes[0] = val >> 8;
	}
	else if (size == 4)
	{
		arg->bytes[3] = val;
		arg->bytes[2] = val >> 8;
		arg->bytes[1] = val >> 16;
		arg->bytes[0] = val >> 24;
	}
}
