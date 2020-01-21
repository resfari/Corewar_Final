/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:23:41 by pnita             #+#    #+#             */
/*   Updated: 2019/12/15 21:23:42 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	delete_oper(t_asm *ass)
{
	t_oper	*oper;
	t_oper	*ptr_oper;

	oper = ass->top;
	while (oper)
	{
		ptr_oper = oper;
		oper = oper->next;
		free(ptr_oper);
	}
}

void	delete_lbl(t_asm *ass)
{
	size_t	i;
	t_lbl	*lbl;
	t_lbl	*ptr_lbl;

	i = 0;
	while (i < LBLS_SIZE)
	{
		if (ass->lbl[i])
		{
			lbl = ass->lbl[i];
			while (lbl)
			{
				ft_strdel(&lbl->name);
				ptr_lbl = lbl;
				lbl = lbl->same_hash;
				free(ptr_lbl);
			}
			ass->lbl[i] = NULL;
		}
		++i;
	}
	free(ass->lbl);
	ass->lbl = NULL;
}

void	delete_lbl_arg(t_asm *ass)
{
	t_lbl_arg	*lbl_arg;
	t_lbl_arg	*ptr_lbl_arg;

	lbl_arg = ass->lbl_arg_top;
	while (lbl_arg)
	{
		ft_strdel(&lbl_arg->lbl);
		ptr_lbl_arg = lbl_arg;
		lbl_arg = lbl_arg->next;
		free(ptr_lbl_arg);
	}
}

void	delete_all(t_asm *ass)
{
	if (ass->line)
		ft_strdel(&ass->line);
	if (ass->name)
		ft_strdel(&ass->name);
	if (ass->comment)
		ft_strdel(&ass->comment);
	if (ass->top)
		delete_oper(ass);
	if (ass->lbl)
		delete_lbl(ass);
	if (ass->lbl_arg_top)
		delete_lbl_arg(ass);
	if (ass->buff)
	{
		free(ass->buff);
		ass->buff = NULL;
	}
	if (ass->output_file_name)
		ft_strdel(&ass->output_file_name);
	free(ass);
	ass = NULL;
}
