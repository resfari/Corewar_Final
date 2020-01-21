/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:27:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/08 17:08:50 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void		ft_compare_magic(t_war *war, char *magic)
{
	int			i;
	const char	orig[32] = "11110011100000111110101000000000";

	i = 0;
	while (i < 32)
	{
		if (magic[i] != orig[i])
		{
			ft_free_exit(war, 7);
		}
		i++;
	}
}

void		ft_check_magic(t_war *war, int num)
{
	unsigned char	*ptr;
	char			fin[33];
	int				j;
	int				d;
	int				i;

	fin[32] = '\0';
	j = 31;
	d = 0;
	ptr = (unsigned char*)&(war->player[num].text[0]);
	while (d < 4)
	{
		i = -1;
		while (++i < 8)
		{
			if (ptr[d] & 1 << i)
				fin[j] = '1';
			else
				fin[j] = '0';
			j--;
		}
		d++;
	}
	ft_compare_magic(war, fin);
}
