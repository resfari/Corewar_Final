/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:08:06 by pnita             #+#    #+#             */
/*   Updated: 2019/12/16 19:08:08 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	get_start_comment(t_asm *ass)
{
	ass->got_start_comment = 1;
	++ass->x;
	while (ass->line[ass->x] && ass->line[ass->x] != '\"')
	{
		ass->comment[ass->c_i++] = ass->line[ass->x++];
		if (ass->c_i > COMMENT_LENGTH)
			error_exit(ass, 10);
	}
	if (ass->line[ass->x] == '\"')
	{
		++ass->x;
		ass->got_comment = 1;
	}
}

void	get_comment_part2(t_asm *ass)
{
	if (!ass->got_comment)
		ft_strdel(&ass->line);
	while (!ass->got_comment && get_next_line(ass->fd, &ass->line) > 0)
	{
		ass->comment[ass->c_i++] = '\n';
		if (ass->c_i > COMMENT_LENGTH)
			error_exit(ass, 10);
		ass->x = 0;
		++ass->y;
		while (ass->line[ass->x] && ass->line[ass->x] != '\"')
		{
			ass->comment[ass->c_i++] = ass->line[ass->x++];
			if (ass->c_i > COMMENT_LENGTH)
				error_exit(ass, 10);
		}
		if (ass->line[ass->x] == '\"')
		{
			++ass->x;
			ass->got_comment = 1;
		}
		if (!ass->got_comment)
			ft_strdel(&ass->line);
	}
	if (!ass->got_start_comment || !ass->got_comment)
		error_exit(ass, 3);
}

void	get_comment(t_asm *ass)
{
	ass->x += ass->cmd_comment_len;
	while (ass->line[ass->x])
	{
		if (ass->line[ass->x] == COMMENT_CHAR
				|| ass->line[ass->x] == ALT_COMMENT_CHAR)
			break ;
		if (ass->line[ass->x] != ' ' && ass->line[ass->x] != '\t')
		{
			if (ass->line[ass->x] == '\"' && !ass->got_start_comment)
				get_start_comment(ass);
			else
				error_exit(ass, 4);
		}
		else
			++ass->x;
	}
	get_comment_part2(ass);
}

void	get_name_and_comment_part2(t_asm *ass)
{
	if (!ft_strncmp(ass->line + ass->x, NAME_CMD_STRING,
			ass->cmd_name_len) && !ass->name[0])
		get_name(ass);
	else if (!ft_strncmp(ass->line + ass->x, COMMENT_CMD_STRING,
			ass->cmd_comment_len) && !ass->comment[0])
		get_comment(ass);
	else
		error_exit(ass, 4);
}

void	get_name_and_comment(t_asm *ass)
{
	while ((!ass->got_start_name || !ass->got_start_comment)
			&& get_next_line(ass->fd, &ass->line) > 0)
	{
		while (ass->line[ass->x])
		{
			if (ass->line[ass->x] == COMMENT_CHAR
					|| ass->line[ass->x] == ALT_COMMENT_CHAR)
				break ;
			if (ass->line[ass->x] != ' ' && ass->line[ass->x] != '\t')
				get_name_and_comment_part2(ass);
			else
				++ass->x;
		}
		++ass->y;
		ass->x = 0;
		ft_strdel(&ass->line);
	}
	if (!ass->got_start_name || !ass->got_start_comment)
		error_exit(ass, 3);
}
