/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:12:06 by pnita             #+#    #+#             */
/*   Updated: 2019/12/16 17:12:07 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	do_with_oper_part2(t_asm *ass, t_oper *oper)
{
	if (oper->comma < oper->tmp_arg)
	{
		if (ass->line[ass->x] != SEPARATOR_CHAR)
			error_exit(ass, 4);
		++oper->comma;
		++ass->x;
	}
	else if (oper->tmp_arg < oper->ops.args_number)
	{
		set_arg_value(ass, &oper->arg[oper->tmp_arg],
				oper->ops.args_type[oper->tmp_arg], oper->ops.t_dir_size);
		++oper->tmp_arg;
	}
	else
		error_exit(ass, 4);
}

void	do_with_oper(t_asm *ass, int op_num)
{
	t_oper	*oper;

	oper = add_oper(ass, op_num);
	while (ass->line[ass->x])
	{
		if (ass->line[ass->x] == COMMENT_CHAR
				|| ass->line[ass->x] == ALT_COMMENT_CHAR)
			break ;
		if (ass->line[ass->x] != ' ' && ass->line[ass->x] != '\t')
			do_with_oper_part2(ass, oper);
		else
			++ass->x;
	}
	if (oper->tmp_arg < oper->ops.args_number)
		error_exit(ass, 5);
	if (oper->ops.args_type_code)
		oper->args_type_code = (oper->arg[0].code << 6)
				| (oper->arg[1].code << 4) | oper->arg[2].code << 2;
	oper->size = (oper->ops.args_type_code ? 2 : 1)
			+ oper->arg[0].size + oper->arg[1].size + oper->arg[2].size;
	if ((ass->current_pos += oper->size) > CHAMP_MAX_SIZE)
		error_exit(ass, 11);
}
