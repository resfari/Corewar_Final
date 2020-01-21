/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:39:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:56:46 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_detect_operation_part2(int op_num, t_war *war, t_crg *crg)
{
	if (op_num == 9)
		ft_zjmp(war, crg);
	else if (op_num == 10)
		ft_ldi(war, crg, 0);
	else if (op_num == 11)
		ft_sti(war, crg);
	else if (op_num == 12)
		ft_fork(war, crg, 0);
	else if (op_num == 13)
		ft_ld(war, crg, 1);
	else if (op_num == 14)
		ft_ldi(war, crg, 1);
	else if (op_num == 15)
		ft_fork(war, crg, 1);
	else if (op_num == 16)
		ft_aff(war, crg);
}

void	ft_detect_operation(int op_num, t_war *war, t_crg *crg)
{
	if (op_num == 1)
		ft_live(war, crg);
	else if (op_num == 2)
		ft_ld(war, crg, 0);
	else if (op_num == 3)
		ft_st(war, crg);
	else if (op_num == 4)
		ft_add(war, crg);
	else if (op_num == 5)
		ft_sub(war, crg);
	else if (op_num == 6)
		ft_and(war, crg);
	else if (op_num == 7)
		ft_or(war, crg);
	else if (op_num == 8)
		ft_xor(war, crg);
	else
		ft_detect_operation_part2(op_num, war, crg);
}
