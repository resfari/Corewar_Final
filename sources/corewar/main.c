/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:53 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 17:01:59 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

int		main(int argc, char **argv)
{
	t_war *war;

	if (!(war = (t_war*)ft_memalloc(sizeof(t_war))))
		return (0);
	if (argc == 1)
	{
		ft_free_exit(war, 11);
	}
	ft_init_main(war, argv, argc);
	ft_read_flags_players(war);
	ft_read_players_code(war);
	ft_decompose_pl_code(war);
	ft_fill_arena(war);
	ft_fill_crg(war);
	ft_greatings(war);
	ft_play_game(war);
	return (0);
}
