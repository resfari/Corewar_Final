/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:00:03 by pnita             #+#    #+#             */
/*   Updated: 2019/12/16 17:00:04 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	set_t_reg(t_asm *ass, t_arg *arg)
{
	int		n;

	++ass->x;
	if (ass->line[ass->x] >= '0' && ass->line[ass->x] <= '9')
	{
		n = ft_atoi_asm(ass, ass->line + ass->x);
		if (n >= 1 && n <= 16)
			fill_arg(arg, n, 1, REG_CODE);
		else
			error_exit(ass, 6);
	}
	else
		error_exit(ass, 4);
}

void	set_lbl(t_asm *ass, t_arg *arg, int size, int code)
{
	char	*lbl;
	int		len;

	++ass->x;
	len = ass->x;
	while (ass->line[len] && ft_strchr(LABEL_CHARS, ass->line[len]))
		++len;
	if (len < ass->x)
		error_exit(ass, 4);
	lbl = ft_str_sub_n(ass->line + ass->x, len - ass->x);
	arg->size = size;
	arg->code = code;
	add_lbl_arg(ass, arg, lbl);
	ass->x = len;
}

void	set_t_dir(t_asm *ass, t_arg *arg, int dir_size)
{
	++ass->x;
	if (ass->line[ass->x] == LABEL_CHAR)
		set_lbl(ass, arg, dir_size, DIR_CODE);
	else if (ass->line[ass->x] == '-'
			|| (ass->line[ass->x] >= '0' && ass->line[ass->x] <= '9'))
		fill_arg(arg, ft_atoi_asm(ass, ass->line + ass->x), dir_size, DIR_CODE);
	else
		error_exit(ass, 4);
}

void	set_t_ind(t_asm *ass, t_arg *arg)
{
	if (ass->line[ass->x] == LABEL_CHAR)
		set_lbl(ass, arg, 2, IND_CODE);
	else if (ass->line[ass->x] == '-')
	{
		++ass->x;
		if (ass->line[ass->x] >= '0' && ass->line[ass->x] <= '9')
			fill_arg(arg, ft_atoi_asm(ass, ass->line + ass->x), 2, IND_CODE);
		else
			error_exit(ass, 4);
	}
	else if (ass->line[ass->x] >= '0' && ass->line[ass->x] <= '9')
		fill_arg(arg, ft_atoi_asm(ass, ass->line + ass->x), 2, IND_CODE);
	else
		error_exit(ass, 4);
}

void	set_arg_value(t_asm *ass, t_arg *arg, char type, int dir_size)
{
	if ((type & T_REG) == T_REG && ass->line[ass->x] == 'r')
		set_t_reg(ass, arg);
	else if ((type & T_DIR) == T_DIR && ass->line[ass->x] == DIRECT_CHAR)
		set_t_dir(ass, arg, dir_size);
	else if ((type & T_IND) == T_IND)
		set_t_ind(ass, arg);
	else
		error_exit(ass, 4);
}
