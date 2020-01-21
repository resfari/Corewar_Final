/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:19:58 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/17 19:53:09 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

int		okrugl(int i)
{
	return ((1500000 - i) / 1000);
}

void	ft_pause(t_war *war)
{
	int i;

	i = 21;
	war->key = 0;
	while (i == 21)
	{
		if (((war->key = getch()) == 32)
				|| ((war->key = getch()) == 27))
		{
			i = 0;
		}
	}
	if (war->key == 27)
	{
		endwin();
		ft_free_exit(war, 0);
	}
	if (war->key == 32)
	{
		war->key = 0;
	}
}

void	ft_key_detect(t_war *war)
{
	if (war->key == 32)
	{
		ft_pause(war);
	}
	else if (war->key == 113 && war->speed > 1000)
	{
		war->speed -= 1000;
	}
	else if (war->key == 119 && war->speed < 1500000)
	{
		war->speed += 1000;
	}
	war->key = 0;
}
