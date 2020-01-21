/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:23:01 by pnita             #+#    #+#             */
/*   Updated: 2019/12/12 15:23:03 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

size_t			hash(char *input)
{
	size_t	hash_num;

	hash_num = 1;
	while (*input)
	{
		hash_num = hash_num * 3 + *(input++);
	}
	return (hash_num % LBLS_SIZE);
}

t_lbl			*create_lbl(char *name, int pos_num)
{
	t_lbl	*lbl;

	lbl = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	lbl->name = name;
	lbl->pos_num = pos_num;
	return (lbl);
}

t_lbl			*find_lbl(t_asm *ass, char *name)
{
	t_lbl		*tmp_lbl;

	tmp_lbl = ass->lbl[hash(name)];
	while (tmp_lbl && ft_strcmp(tmp_lbl->name, name))
		tmp_lbl = tmp_lbl->same_hash;
	return (tmp_lbl);
}

void			do_with_lbl_part2(t_asm *ass, char **str)
{
	t_lbl	*lbl;
	char	exist;

	exist = 0;
	lbl = ass->lbl[hash(*str)];
	if (!ft_strcmp(*str, lbl->name))
		exist = 1;
	else
	{
		while (lbl->same_hash)
		{
			lbl = lbl->same_hash;
			if (!ft_strcmp(*str, lbl->name))
			{
				exist = 1;
				break ;
			}
		}
	}
	if (!exist)
		lbl->same_hash = create_lbl(*str, ass->current_pos);
	else
		ft_strdel(str);
}

void			do_with_lbl(t_asm *ass, int len)
{
	char	*str;

	str = ft_str_sub_n(ass->line + ass->x, len - ass->x);
	if (!ass->lbl[hash(str)])
		ass->lbl[hash(str)] = create_lbl(str, ass->current_pos);
	else
		do_with_lbl_part2(ass, &str);
	ass->x = len + 1;
	while (ass->line[ass->x])
	{
		if (ass->line[ass->x] == COMMENT_CHAR
				|| ass->line[ass->x] == ALT_COMMENT_CHAR)
			break ;
		if (ass->line[ass->x] == ' ' || ass->line[ass->x] == '\t')
			++ass->x;
		else if (ass->line[ass->x] && !detect_op(ass))
			error_exit(ass, 7);
	}
}
