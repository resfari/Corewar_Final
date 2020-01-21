/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_crg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:11:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/06 16:57:46 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/corewar/corewar.h"

t_crg	*ft_create_crg(t_war *war, int num)
{
	t_crg *new;

	if (!(new = (t_crg*)ft_memalloc(sizeof(t_crg) * 1)))
		ft_free_exit(war, 1);
	new->player = num;
	new->op = -1;
	new->pos = war->player[num].start_pos;
	new->reg[1] = num * -1;
	return (new);
}

t_crg	*ft_add_crg(t_war *war, t_crg *crg, int num)
{
	t_crg *tmp;

	tmp = crg;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = ft_create_crg(war, num);
	tmp->next->prev = tmp;
	return (tmp->next);
}

void	ft_fill_crg(t_war *war)
{
	int		i;
	t_crg	*crg;

	i = war->numb_players;
	crg = NULL;
	war->winner = i;
	while (i >= 1)
	{
		if (crg == NULL)
		{
			crg = ft_create_crg(war, i);
			war->top = crg;
		}
		else
		{
			war->bot = ft_add_crg(war, crg, i);
		}
		i--;
	}
	if (war->numb_players == 1)
		war->bot = crg;
}
