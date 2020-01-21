/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:07:48 by pnita             #+#    #+#             */
/*   Updated: 2019/12/15 17:07:49 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	put_s_in_bytes(unsigned char *s, int size, int val)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < size)
	{
		s[i] = val >> (8 * (size - 1 - i));
		++i;
	}
}

void	join_nuls_to_buff(t_asm *ass, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ass->buff[ass->buff_i++] = 0;
		++i;
	}
}

void	join_champ_code(t_asm *ass)
{
	t_oper	*oper;
	int		i;
	int		j;

	oper = ass->top;
	while (oper)
	{
		ass->buff[ass->buff_i++] = oper->ops.opcode;
		if (oper->ops.args_type_code)
			ass->buff[ass->buff_i++] = oper->args_type_code;
		i = 0;
		while (i < oper->ops.args_number)
		{
			j = 0;
			while (j < oper->arg[i].size)
			{
				ass->buff[ass->buff_i++] = oper->arg[i].bytes[j++];
			}
			++i;
		}
		oper = oper->next;
	}
}

void	forme_output(t_asm *ass)
{
	unsigned char	*s;

	ass->buff = (unsigned char*)ft_memalloc(sizeof(unsigned char) *
			(COREWAR_EXEC_MAGIC + PROG_NAME_LENGTH
			+ 4 + 4 + 2048 + 4 + ass->current_pos));
	s = (unsigned char*)ft_memalloc(sizeof(unsigned char) * 5);
	put_s_in_bytes(s, 4, COREWAR_EXEC_MAGIC);
	join_uns_s_to_buff(ass, s, 4);
	join_s_to_buff(ass, ass->name);
	join_nuls_to_buff(ass, PROG_NAME_LENGTH - ass->n_i);
	join_nuls_to_buff(ass, 4);
	put_s_in_bytes(s, 4, ass->current_pos);
	join_uns_s_to_buff(ass, s, 4);
	join_s_to_buff(ass, ass->comment);
	join_nuls_to_buff(ass, COMMENT_LENGTH - ass->c_i + 4);
	join_champ_code(ass);
	free(s);
	s = NULL;
}

void	write_to_file(t_asm *ass)
{
	int	fd;
	int	len;
	int	i;

	forme_output(ass);
	len = ft_strlen(ass->file_name);
	ass->output_file_name = ft_strnew(len + 2);
	i = 0;
	while (i < len - 1)
	{
		ass->output_file_name[i] = ass->file_name[i];
		++i;
	}
	ass->output_file_name[i++] = 'c';
	ass->output_file_name[i++] = 'o';
	ass->output_file_name[i++] = 'r';
	if ((fd = open(ass->output_file_name,
			O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error_exit(ass, 12);
	write(fd, ass->buff, ass->buff_i);
	close(fd);
	ft_printf("Writing output program to %s\n", ass->output_file_name);
	delete_all(ass);
}
