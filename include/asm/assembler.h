/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:22:11 by pnita             #+#    #+#             */
/*   Updated: 2019/12/10 20:23:10 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "../../ft_printf/include/ft_printf.h"
# include "op.h"
# include "operations.h"

# define LBLS_SIZE 500

typedef struct			s_lbl
{
	char				*name;
	int					pos_num;
	struct s_lbl		*same_hash;
}						t_lbl;

typedef struct			s_arg
{
	unsigned char		bytes[4];
	int					size;
	char				code;
}						t_arg;

typedef struct			s_lbl_arg
{
	struct s_arg		*arg;
	int					oper_pos;
	char				*lbl;
	struct s_lbl_arg	*next;
}						t_lbl_arg;

typedef struct			s_oper
{
	int					op_num;
	t_ops				ops;
	unsigned char		args_type_code;
	int					size;
	struct s_arg		arg[3];
	int					tmp_arg;
	int					comma;
	struct s_oper		*next;
}						t_oper;

typedef struct			s_asm
{
	int					fd;
	char				*line;
	char				*file_name;
	int					y;
	int					x;
	int					cmd_name_len;
	int					cmd_comment_len;
	char				*name;
	int					n_i;
	char				got_name;
	char				got_start_name;
	char				*comment;
	int					c_i;
	char				got_comment;
	char				got_start_comment;
	int					current_pos;
	t_oper				*top;
	t_oper				*bot;
	t_lbl				**lbl;
	t_lbl_arg			*lbl_arg_top;
	t_lbl_arg			*lbl_arg_bot;
	char				*error_str;
	unsigned char		*buff;
	size_t				buff_i;
	char				*output_file_name;
}						t_asm;

char					*ft_str_sub_n(char *s1, size_t n);
int						ft_atoi_asm(t_asm *ass, const char *str);
void					delete_all(t_asm *ass);
void					error_exit(t_asm *ass, int error_num);

void					get_name(t_asm *ass);
void					get_comment(t_asm *ass);
void					get_name_and_comment(t_asm *ass);

size_t					hash(char *input);
t_lbl					*create_lbl(char *name, int pos_num);
t_lbl					*find_lbl(t_asm *ass, char *name);

void					fill_arg(t_arg *arg, int val, int size, int code);
t_oper					*create_oper(int op_num);
t_oper					*add_oper(t_asm *ass, int op_num);

void					set_arg_value(t_asm *ass, t_arg *arg,
		char type, int dir_size);
void					do_with_oper(t_asm *ass, int op_num);
int						detect_op(t_asm *ass);

void					do_with_lbl(t_asm *ass, int len);

void					add_lbl_arg(t_asm *ass, t_arg *arg, char *lbl);

void					join_uns_s_to_buff(t_asm *ass,
		unsigned char *s, int size);
void					join_s_to_buff(t_asm *ass, char *s);
void					write_to_file(t_asm *ass);

#endif
