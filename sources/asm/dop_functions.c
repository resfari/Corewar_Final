/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:22:44 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 22:22:45 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

char	*ft_str_sub_n(char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	if (!s1 || ft_strlen(s1) < n)
		return (NULL);
	s2 = ft_strnew(n);
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		++i;
	}
	return (s2);
}

int		ft_atoi_asm(t_asm *ass, const char *str)
{
	char					*s;
	unsigned long long int	i;
	int						sign;
	int						sz;

	s = (char*)str;
	sign = 1;
	if (*s == '-')
		if (*(s++) == '-')
			sign = -1;
	i = 0;
	sz = 0;
	while (*s >= '0' && *s <= '9')
	{
		i = i * 10 + *(s++) - '0';
		++sz;
		if ((i > 9223372036854775807 || sz > 19) && sign == -1)
			return (0);
		else if ((i > 9223372036854775807 || sz > 19) && sign == 1)
			return (-1);
	}
	ass->x += s - str;
	return ((int)i * sign);
}
