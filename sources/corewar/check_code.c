/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:53:39 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/08 17:52:13 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_check_len_code(t_war *war, int num)
{
	int res;
	int pos;

	pos = PROG_NAME_LENGTH + 8;
	res = (war->player[num].text[pos] << 24)
			| (war->player[num].text[pos + 1] << 16)
			| (war->player[num].text[pos + 2] << 8)
			| (war->player[num].text[pos + 3]);
	war->player[num].byte_len_code = res;
}

void	ft_check_code(t_war *war, int num)
{
	int i;
	int j;

	j = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH;
	i = 0;
	while (j < war->player[num].text_len)
	{
		war->player[num].code[i] = war->player[num].text[j];
		i++;
		j++;
	}
	war->player[num].code[i] = '\0';
	war->player[num].code_len = j - (16 + PROG_NAME_LENGTH + COMMENT_LENGTH);
	if (war->player[num].code_len > CHAMP_MAX_SIZE)
		ft_free_exit(war, 9);
	if (war->player[num].code_len != war->player[num].byte_len_code)
		ft_free_exit(war, 2);
}
