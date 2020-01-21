/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:19:51 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 20:19:52 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

int		create_ass(t_asm **ass)
{
	t_asm	*new;

	if (!(new = (t_asm*)ft_memalloc(sizeof(t_asm))))
		return (0);
	new->cmd_name_len = ft_strlen(NAME_CMD_STRING);
	new->cmd_comment_len = ft_strlen(COMMENT_CMD_STRING);
	new->name = ft_strnew(PROG_NAME_LENGTH);
	new->comment = ft_strnew(COMMENT_LENGTH);
	new->lbl = (t_lbl**)ft_memalloc(sizeof(t_lbl*) * LBLS_SIZE);
	*ass = new;
	return (1);
}

void	reading_part2(t_asm *ass)
{
	int	len;

	len = ass->x;
	while (ass->line[len] && ft_strchr(LABEL_CHARS, ass->line[len]))
		++len;
	if (ass->line[len] == LABEL_CHAR)
		do_with_lbl(ass, len);
	else if (ass->line[ass->x] && !detect_op(ass))
		error_exit(ass, 7);
}

void	reading(t_asm *ass)
{
	get_name_and_comment(ass);
	while (get_next_line(ass->fd, &ass->line) > 0)
	{
		ass->x = 0;
		while (ass->line[ass->x])
		{
			if (ass->line[ass->x] == COMMENT_CHAR
					|| ass->line[ass->x] == ALT_COMMENT_CHAR)
				break ;
			if (ass->line[ass->x] == ' ' || ass->line[ass->x] == '\t')
				++ass->x;
			else
				reading_part2(ass);
		}
		++ass->y;
		ft_strdel(&ass->line);
	}
}

void	fill_lbl_arg(t_asm *ass)
{
	t_lbl_arg	*lbl_arg;
	t_lbl		*lbl;

	lbl_arg = ass->lbl_arg_top;
	while (lbl_arg)
	{
		if (!(lbl = find_lbl(ass, lbl_arg->lbl)))
		{
			ass->error_str = lbl_arg->lbl;
			error_exit(ass, 8);
		}
		else
			fill_arg(lbl_arg->arg, lbl->pos_num - lbl_arg->oper_pos,
					lbl_arg->arg->size, lbl_arg->arg->code);
		lbl_arg = lbl_arg->next;
	}
}

int		main(int argc, char **argv)
{
	t_asm		*ass;

	if (argc == 1)
	{
		ft_printf("Usage: ./asm (champion.s)\n");
		return (0);
	}
	if (argc > 2 || !ft_check_s1_end_with_s2(argv[1], ".s"))
		error_exit(NULL, 0);
	if (!create_ass(&ass))
		return (0);
	ass->file_name = argv[1];
	if ((ass->fd = open(ass->file_name, O_RDONLY)) == -1)
		error_exit(ass, 1);
	reading(ass);
	fill_lbl_arg(ass);
	write_to_file(ass);
	return (0);
}
