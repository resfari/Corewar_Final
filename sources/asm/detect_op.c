/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:03:48 by pnita             #+#    #+#             */
/*   Updated: 2019/12/12 15:03:49 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

int		detect_op_part4(t_asm *ass)
{
	if (!ft_strncmp(ass->line + ass->x, "lldi", 4))
	{
		ass->x += 4;
		do_with_oper(ass, 13);
	}
	else if (!ft_strncmp(ass->line + ass->x, "lld", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 12);
	}
	else if (!ft_strncmp(ass->line + ass->x, "lfork", 5))
	{
		ass->x += 5;
		do_with_oper(ass, 14);
	}
	else if (!ft_strncmp(ass->line + ass->x, "aff", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 15);
	}
	else
		return (0);
	return (1);
}

int		detect_op_part3(t_asm *ass)
{
	if (!ft_strncmp(ass->line + ass->x, "or", 2))
	{
		ass->x += 2;
		do_with_oper(ass, 6);
	}
	else if (!ft_strncmp(ass->line + ass->x, "xor", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 7);
	}
	else if (!ft_strncmp(ass->line + ass->x, "zjmp", 4))
	{
		ass->x += 4;
		do_with_oper(ass, 8);
	}
	else if (!ft_strncmp(ass->line + ass->x, "fork", 4))
	{
		ass->x += 4;
		do_with_oper(ass, 11);
	}
	else if (!detect_op_part4(ass))
		return (0);
	return (1);
}

int		detect_op_part2(t_asm *ass)
{
	if (!ft_strncmp(ass->line + ass->x, "st", 2))
	{
		ass->x += 2;
		do_with_oper(ass, 2);
	}
	else if (!ft_strncmp(ass->line + ass->x, "add", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 3);
	}
	else if (!ft_strncmp(ass->line + ass->x, "sub", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 4);
	}
	else if (!ft_strncmp(ass->line + ass->x, "and", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 5);
	}
	else if (!detect_op_part3(ass))
		return (0);
	return (1);
}

int		detect_op(t_asm *ass)
{
	if (!ft_strncmp(ass->line + ass->x, "live", 4))
	{
		ass->x += 4;
		do_with_oper(ass, 0);
	}
	else if (!ft_strncmp(ass->line + ass->x, "ldi", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 9);
	}
	else if (!ft_strncmp(ass->line + ass->x, "ld", 2))
	{
		ass->x += 2;
		do_with_oper(ass, 1);
	}
	else if (!ft_strncmp(ass->line + ass->x, "sti", 3))
	{
		ass->x += 3;
		do_with_oper(ass, 10);
	}
	else if (!detect_op_part2(ass))
		return (0);
	return (1);
}
