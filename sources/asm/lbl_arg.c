/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbl_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:10:21 by pnita             #+#    #+#             */
/*   Updated: 2019/12/14 22:10:23 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

t_lbl_arg	*create_lbl_arg(t_arg *arg, int oper_pos, char *lbl)
{
	t_lbl_arg	*lbl_arg;

	lbl_arg = (t_lbl_arg*)ft_memalloc(sizeof(t_lbl_arg));
	lbl_arg->arg = arg;
	lbl_arg->oper_pos = oper_pos;
	lbl_arg->lbl = lbl;
	return (lbl_arg);
}

void		add_lbl_arg(t_asm *ass, t_arg *arg, char *lbl)
{
	if (!ass->lbl_arg_top)
	{
		ass->lbl_arg_top = create_lbl_arg(arg, ass->current_pos, lbl);
		ass->lbl_arg_bot = ass->lbl_arg_top;
	}
	else
	{
		ass->lbl_arg_bot->next = create_lbl_arg(arg, ass->current_pos, lbl);
		ass->lbl_arg_bot = ass->lbl_arg_bot->next;
	}
}
