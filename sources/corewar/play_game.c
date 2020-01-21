/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:18:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/17 16:47:44 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

int		ft_check_live_crg(t_war *war)
{
	t_crg *tmp;

	tmp = war->top;
	war->numb_crg = 0;
	while (tmp)
	{
		if (tmp->live == 0)
		{
			war->arena[GG(tmp->pos)].busy = 0;
			war->arena[GG(tmp->pos)].crg_clr = 0;
			tmp->die = 1;
		}
		if (tmp->die == 0)
		{
			tmp->live = 0;
			war->numb_crg++;
		}
		tmp = tmp->next;
	}
	return (war->numb_crg);
}

void	ft_play_game_part1(t_war *war)
{
	if (war->to_die <= 0)
	{
		if (war->need_to_draw == 1)
			ft_print_1(war, 1);
		else
			ft_printf("Contestant %d, \"%s\", has won !\n",
					war->winner, war->player[war->winner].name);
		ft_free_exit(war, 0);
	}
}

void	ft_play_game_part2(t_war *war)
{
	if (war->cycle == war->to_die)
	{
		war->check_num++;
		if (ft_check_live_crg(war) == 0)
		{
			if (war->need_to_draw == 1)
				ft_print_1(war, 1);
			else
				ft_printf("Contestant %d, \"%s\", has won !\n",
						war->winner, war->player[war->winner].name);
			ft_free_exit(war, 0);
		}
		if (war->check_num == 10 || war->live >= NBR_LIVE)
		{
			war->to_die -= CYCLE_DELTA;
			war->check_num = 0;
		}
		war->cycle = 0;
		war->live = 0;
	}
}

void	ft_play_game_part3(t_war *war)
{
	if (war->need_to_draw == 0 && war->dump_cycle == war->all_cycle
			&& (war->dump == 1 || war->dump2 == 1))
	{
		ft_print_arena(war);
		ft_free_exit(war, 0);
	}
	if (war->need_to_draw == 1)
	{
		ft_print_1(war, 0);
		usleep(war->speed);
	}
}

void	ft_play_game(t_war *war)
{
	t_crg *tmp;

	ft_init_first_cycle(war);
	if (war->need_to_draw == 1)
		ft_init_ncurses();
	while ((war->key = getch()) != 27)
	{
		if (war->key == 32 || war->key == 113 || war->key == 119)
			ft_key_detect(war);
		tmp = war->top;
		ft_check_status_of_crg(war, tmp);
		ft_play_game_part1(war);
		ft_play_game_part2(war);
		ft_play_game_part3(war);
		war->cycle++;
		war->all_cycle++;
	}
	if (war->key == 27)
	{
		endwin();
		ft_free_exit(war, 0);
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
			war->winner, war->player[war->winner].name);
	ft_free_exit(war, 0);
}
