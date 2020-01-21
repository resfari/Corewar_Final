# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    our_champ.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnita <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:54:08 by pnita             #+#    #+#              #
#    Updated: 2019/12/18 17:54:23 by pnita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name				"Meepo"
.comment			"I am lose every day"

copy:
			sti		r1,		%:live,		%1
			ld		%66,	r2
			ld		%1,		r3
			ld		%167703296,	r4
			aff		r2
			zjmp	%:live	

live:
			live	%666
			fork	%:copy
			zjmp	%:copy

garbage:
			sti		r3,		%123,		%1
			sti		r1,		%120,		%1
			sti		r3,		%133,		%1
			sti		r1,		%130,		%1
			sti		r3,		%143,		%1
			sti		r1,		%140,		%1
			sti		r3,		%153,		%1
			sti		r1,		%150,		%1
			sti		r4,		%160,		%1
			add		r7, r6, r5
