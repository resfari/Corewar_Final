/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:29:13 by pnita             #+#    #+#             */
/*   Updated: 2019/12/11 22:29:14 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/asm/assembler.h"

void	error_exit_part2(t_asm *ass, int error_num)
{
	if (error_num == 7)
		ft_printf("ERROR. Incorrect label starting with \"%c\" "
				"at [%.3i:%.3i]\n", ass->line[ass->x], ass->y + 1, ass->x + 1);
	else if (error_num == 8)
		ft_printf("ERROR. Label \"%s\" not found\n", ass->error_str);
	else if (error_num == 9)
		ft_printf("ERROR. Size of champion name = %d > %d\n",
				ass->n_i, PROG_NAME_LENGTH);
	else if (error_num == 10)
		ft_printf("ERROR. Size of champion comment = %d > %d\n",
				ass->c_i, COMMENT_LENGTH);
	else if (error_num == 11)
		ft_printf("ERROR. Size of champion code = %d > %d\n",
				ass->current_pos, CHAMP_MAX_SIZE);
	else if (error_num == 12)
		ft_printf("ERROR. Can't create file \"%s\". "
				"Permission denied\n", ass->output_file_name);
}

void	error_exit(t_asm *ass, int error_num)
{
	if (!error_num)
		ft_printf("ERROR. Can be only one file and "
				"it's name must end with \".s\"\n");
	else if (error_num == 1)
		ft_printf("ERROR. Can't open file \"%s\". "
				"Permission denied\n", ass->file_name);
	else if (error_num == 2)
		ft_printf("ERROR. Can't read %s\n", ass->file_name);
	else if (error_num == 3)
		ft_printf("ERROR. Not correct champion name or champion comment\n");
	else if (error_num == 4)
		ft_printf("ERROR. Unexpected symbol \"%c\" at [%.3i:%.3i]\n",
				ass->line[ass->x], ass->y + 1, ass->x + 1);
	else if (error_num == 5)
		ft_printf("ERROR. Not full operation at [%.3i:%.3i]\n",
				ass->y + 1, ass->x + 1);
	else if (error_num == 6)
		ft_printf("ERROR. T_REG can be only from 1 to 16 at [%.3i:%.3i]\n",
				ass->y + 1, ass->x + 1);
	else
		error_exit_part2(ass, error_num);
	if (ass)
		delete_all(ass);
	exit(1);
}
