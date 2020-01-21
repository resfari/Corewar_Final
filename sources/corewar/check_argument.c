/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:07:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/08 17:03:25 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

int		ft_calc_bytes_to_skip(int *mass, int dir_size, int len)
{
	int i;
	int bytes;

	i = 0;
	bytes = 0;
	while (i < len)
	{
		if (mass[i] == 3)
			bytes += 1;
		else if (mass[i] == 5)
			bytes += dir_size;
		else if (mass[i] == 7)
			bytes += 2;
		i++;
	}
	return (bytes + 2);
}

void	ft_init_args_in_crg(t_crg *crg)
{
	crg->args[0] = 0;
	crg->args[1] = 0;
	crg->args[2] = 0;
}

void	ft_read_one_byte_for_arg(t_war *war, t_crg *crg)
{
	char	*ptr;
	int		d;
	int		byte;
	int		correct;
	int		i;

	d = 0;
	i = 0;
	byte = 7;
	ft_init_args_in_crg(crg);
	ptr = (char*)&(war->arena[GG((crg->pos + 1))].code);
	while (byte > 1)
	{
		correct = 1;
		if (ptr[d] & 1 << byte)
		{
			crg->args[i] = 5;
			correct = 0;
		}
		byte--;
		if (ptr[d] & 1 << byte)
			crg->args[i] += 2 + correct;
		i++;
		byte--;
	}
}

int		ft_check_argument(t_war *war, t_crg *crg, int oper)
{
	int i;

	i = 0;
	ft_read_one_byte_for_arg(war, crg);
	while (i < war->opp[oper].arg_len)
	{
		if (crg->args[i] == 0 || war->opp[oper].types[i] % crg->args[i] != 0)
		{
			crg->bytes_to_go = ft_calc_bytes_to_skip(crg->args,
			war->opp[oper].dir_size, war->opp[oper].arg_len);
			return (0);
		}
		i++;
	}
	crg->bytes_to_go = ft_calc_bytes_to_skip(crg->args,
	war->opp[oper].dir_size, war->opp[oper].arg_len);
	return (1);
}
