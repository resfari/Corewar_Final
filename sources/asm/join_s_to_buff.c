/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_buff2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:52:31 by pnita             #+#    #+#             */
/*   Updated: 2019/12/16 16:52:33 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	join_uns_s_to_buff(t_asm *ass, unsigned char *s, int size)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (i < size)
	{
		ass->buff[ass->buff_i++] = s[i++];
	}
}

void	join_s_to_buff(t_asm *ass, char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ass->buff[ass->buff_i++] = s[i++];
	}
}
