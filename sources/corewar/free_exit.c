/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:47:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/08 17:52:32 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

void	ft_print_usage(void)
{
	ft_putstr("#####################################"
		"###########################################\n");
	ft_putstr("Usage: ./corewar [-dump N | -v | -live] "
		"[-a] [-n N] <champion1.cor> <...>\n");
	ft_putstr("    -dump N      : Dumps memory "
		"after N cycles then exits(64 octets per line)\n");
	ft_putstr("    -d32 N      : Dumps memory "
		"after N cycles then exits(32 octets per line)\n");
	ft_putstr("    -live        : Show lives\n");
	ft_putstr("    -v           : Ncurses output mode\n");
	ft_putstr("    -a        	 : "
		"Prints output from \"aff\" (Default is to hide it)\n");
	ft_putstr("    -n N         : Set <N> of the next player\n");
	ft_putstr("###########################"
		"#####################################################\n");
}

void	ft_error_print_part2(int num_error)
{
	if (num_error == 6)
	{
		ft_putstr("Error: Wrong flags\n");
		ft_print_usage();
	}
	else if (num_error == 7)
		ft_putstr("Error: Magic header\n");
	else if (num_error == 8)
		ft_putstr("Error: Character in file\n");
	else if (num_error == 9)
		ft_putstr("Error: File have wrong size\n");
	else if (num_error == 12)
		ft_putstr("Error: Not *.cor file\n");
}

void	ft_error_print(int num_error)
{
	if (num_error == 1)
		ft_putstr("Error: Malloc\n");
	else if (num_error == 2)
		ft_putstr("File has a code size that"
			"differ from what its header says\n");
	else if (num_error == 3)
		ft_putstr("File error\n");
	else if (num_error == 4)
		ft_putstr("Error: Wrong number of players\n");
	else if (num_error == 5 || num_error == 10)
	{
		ft_putstr("Error: Check flag: dump\n");
		ft_print_usage();
	}
	else
		ft_error_print_part2(num_error);
}

void	free_all(t_war *war)
{
	t_crg *help;
	t_crg *f_help;

	f_help = war->top;
	while (f_help)
	{
		help = f_help;
		f_help = f_help->next;
		free(help);
	}
	free(war);
}

void	ft_free_exit(t_war *war, int n_error)
{
	if (n_error == 11)
	{
		ft_print_usage();
	}
	else if (n_error != 0)
	{
		ft_error_print(n_error);
	}
	free_all(war);
	exit(1);
}
