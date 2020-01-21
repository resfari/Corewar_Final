/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:31:37 by pnita             #+#    #+#             */
/*   Updated: 2019/12/11 22:31:38 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	get_start_name(t_asm *ass)
{
	ass->got_start_name = 1;
	++ass->x;
	while (ass->line[ass->x] && ass->line[ass->x] != '\"')
	{
		ass->name[ass->n_i++] = ass->line[ass->x++];
		if (ass->n_i > PROG_NAME_LENGTH)
			error_exit(ass, 9);
	}
	if (ass->line[ass->x] == '\"')
	{
		++ass->x;
		ass->got_name = 1;
	}
}

void	get_name_part2(t_asm *ass)
{
	if (!ass->got_name)
		ft_strdel(&ass->line);
	while (!ass->got_name && get_next_line(ass->fd, &ass->line) > 0)
	{
		ass->name[ass->n_i++] = '\n';
		if (ass->n_i > PROG_NAME_LENGTH)
			error_exit(ass, 9);
		ass->x = 0;
		++ass->y;
		while (ass->line[ass->x] && ass->line[ass->x] != '\"')
		{
			ass->name[ass->n_i++] = ass->line[ass->x++];
			if (ass->n_i > PROG_NAME_LENGTH)
				error_exit(ass, 9);
		}
		if (ass->line[ass->x] == '\"')
		{
			++ass->x;
			ass->got_name = 1;
		}
		if (!ass->got_name)
			ft_strdel(&ass->line);
	}
	if (!ass->got_start_name || !ass->got_name)
		error_exit(ass, 3);
}

void	get_name(t_asm *ass)
{
	ass->x += ass->cmd_name_len;
	while (ass->line[ass->x])
	{
		if (ass->line[ass->x] == COMMENT_CHAR
				|| ass->line[ass->x] == ALT_COMMENT_CHAR)
			break ;
		if (ass->line[ass->x] != ' ' && ass->line[ass->x] != '\t')
		{
			if (ass->line[ass->x] == '\"' && !ass->got_start_name)
				get_start_name(ass);
			else
				error_exit(ass, 4);
		}
		else
			++ass->x;
	}
	get_name_part2(ass);
}
