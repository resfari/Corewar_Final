/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:02:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/12/17 19:49:59 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdio.h>
# include "../../ft_printf/include/ft_printf.h"
# include "op.h"
# include "curses.h"
# include <stdarg.h>
# include <limits.h>

# define REG 3
# define DIR 5
# define IND 7

# define WP(x) (x > 4095 ? x % 4096 : x)
# define GG(x) ((x) % MEM_SIZE < 0 ? (x) % MEM_SIZE + MEM_SIZE : (x) % MEM_SIZE)

# define MAX_CODE_SIZE  (COMMENT_LENGTH + CHAMP_MAX_SIZE + PROG_NAME_LENGTH)

typedef struct			s_opp
{
	int					arg_len;
	int					types[3];
	int					dir_size;
	int					cycle;
}						t_opp;

typedef struct			s_player
{
	int					live;
	char				*path;
	char				comment[COMMENT_LENGTH + 1];
	char				name[PROG_NAME_LENGTH + 1];
	char				code[CHAMP_MAX_SIZE + 1];
	int					byte_len_code;
	int					code_len;
	int					start_pos;
	int					text_len;
	unsigned char		text[MAX_CODE_SIZE + 16];
}						t_player;

typedef struct			s_arena
{
	unsigned char		code;
	int					busy;
	int					color;
	int					crg_clr;

}						t_arena;

typedef struct			s_crg
{
	struct s_crg		*next;
	struct s_crg		*prev;
	int					player;
	int					pos;
	int					carry;
	int					to_do;
	int					bytes_to_go;
	int					reg[REG_NUMBER + 1];
	int					die;
	int					moved;
	int					op;
	int					args[3];
	int					live;
}						t_crg;

typedef struct			s_war
{
	t_player			player[5];
	t_arena				arena[MEM_SIZE];
	char				**argv;
	int					argc;
	int					reserved_num[5];
	int					reserved_wo_n[5];
	int					numb_players;
	int					numb_crg;
	t_crg				*top;
	t_crg				*bot;
	int					winner;
	int					cycle;
	int					to_die;
	int					live;
	int					check_num;
	t_opp				opp[17];
	int					all_cycle;
	int					need_to_draw;
	int					dump;
	int					dump2;
	int					dump_cycle;
	int					vis_live;
	int					aff;
	int					arg1;
	int					arg2;
	int					arg3;
	int					key;
	unsigned int		speed;
}						t_war;

void					ft_read_file(char *name_file);
void					ft_take_dump(t_war *war, int index);
void					ft_read_flags_players(t_war *war);
void					ft_init_main(t_war *war, char **argv, int argc);
int						ft_give_free_num(t_war *war);
int						ft_check_free_num(t_war *war, int num);
int						ft_check_valid_num(t_war *war, char *line);
int						ft_check_order_amount_players(t_war *war);
void					ft_read_players_code(t_war *war);
void					ft_decompose_pl_code(t_war *war);
void					ft_free_exit(t_war *war, int n_error);
void					ft_check_magic(t_war *war, int num);
void					ft_check_name(t_war *war, int num);
void					ft_check_comment(t_war *war, int num);
void					ft_check_code(t_war *war, int num);
void					ft_fill_arena(t_war *war);
void					ft_fill_crg(t_war *war);
void					ft_greatings(t_war *war);
t_crg					*ft_init_reg_in_crg(t_crg *crg, int num);
void					ft_check_status_of_crg(t_war *war, t_crg *crg);
void					ft_init_opp(t_war *war);
t_crg					*ft_create_crg(t_war *war, int num);
void					ft_init_first_cycle(t_war *war);
void					ft_play_game(t_war *war);
void					ft_detect_operation(int op, t_war *war, t_crg *crg);
void					ft_check_status_of_crg(t_war *war, t_crg *crg);
int						ft_check_argument(t_war *war, t_crg *crg, int oper);
void					ft_move_crg(t_war *war, t_crg *crg, int move_to);
void					ft_print_crg_list(t_war *war);
void					ft_print_code_for_each_player(t_war *war);
void					ft_print_arena(t_war *war);
void					ft_print_text(t_war *war);
void					ft_test_bytes(t_war *war, int num);
void					ft_test_4bytes(t_war *war, int num);
int						get_arg_reg(t_war *war, int pos);
int						get_arg_dir(t_war *war, int pos, int size);
int						get_arg_ind(t_war *war, int pos);
void					ft_live(t_war *war, t_crg *crg);
void					ft_ld(t_war *war, t_crg *crg, int cases);
void					ft_st(t_war *war, t_crg *crg);
void					ft_add(t_war *war, t_crg *crg);
void					ft_sub(t_war *war, t_crg *crg);
void					ft_and_or_xor_do_with_arg0(t_war *war, t_crg *crg,
						int *pos, int *bit_val);
void					ft_and(t_war *war, t_crg *crg);
void					ft_or(t_war *war, t_crg *crg);
void					ft_xor(t_war *war, t_crg *crg);
void					ft_zjmp(t_war *war, t_crg *crg);
void					ft_andor_calc_move(t_war *war, t_crg *crg);
void					ft_ldi(t_war *war, t_crg *crg, int cases);
void					ft_fork(t_war *war, t_crg *crg, int cases);
void					ft_sti(t_war *war, t_crg *crg);
void					ft_aff(t_war *war, t_crg *crg);
void					ft_check_len_code(t_war *war, int num);
void					ft_print_1(t_war *war, int winner);
void					ft_init_ncurses(void);
void					ft_key_detect(t_war *war);
int						okrugl(int i);

#endif
