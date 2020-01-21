# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnita <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:56:38 by pnita             #+#    #+#              #
#    Updated: 2019/12/18 17:56:40 by pnita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME = asm
COREWAR_NAME = corewar

FLAGS = #-Wall -Werror -Wextra

FT_PRINTF = ft_printf

# Headers

HEADER = ./include/

# asm

ASM_HEADERS_LIST = \
	op.h\
	assembler.h\
	operations.h
ASM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(ASM_HEADERS_LIST))

# corewar

COREWAR_HEADERS_LIST = \
	op.h\
	corewar.h
COREWAR_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(COREWAR_HEADERS_LIST))

# Sources

# asm

ASM_SOURCES_DIRECTORY = ./sources/asm/
ASM_SOURCES_LIST = \
	assembler.c \
	dop_functions.c \
	error_exit.c \
	name_comment.c \
	get_name.c \
	set_arg.c \
	do_with_oper.c \
	detect_op.c \
	lbl.c \
	oper.c \
	arg.c \
	lbl_arg.c \
	join_s_to_buff.c \
	do_with_buff.c \
	delete.c
ASM_SOURCES = $(addprefix $(ASM_SOURCES_DIRECTORY), $(ASM_SOURCES_LIST))

# corewar

COREWAR_SOURCES_DIRECTORY = ./sources/corewar/
COREWAR_SOURCES_LIST = \
	main.c \
	reading_take_dump.c \
	read_flags_players.c \
	init_main.c \
	check_player.c \
	read_players_code.c \
	decompose_code.c \
	check_magic.c \
	free_exit.c \
	check_name_and_comment.c \
	fill_arena.c \
	check_code.c \
	fill_crg.c \
	greatings.c \
	init_opp.c \
	init_first_cycle.c \
	play_game.c \
	check_status_of_crg.c \
	check_argument.c \
	detect_operation.c \
	move_crg.c \
	get_arg.c \
	ft_live.c \
	ft_ld.c \
	ft_st.c \
	ft_add.c \
	ft_sub.c \
	ft_and.c \
	ft_or.c \
	ft_xor.c \
	ft_zjmp.c \
	ft_ldi.c \
	ft_sti.c \
	ft_fork.c \
	ft_aff.c \
	ft_print.c \
	ft_key_detect.c
COREWAR_SOURCES = $(addprefix $(COREWAR_SOURCES_DIRECTORY), $(COREWAR_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objects/

# asm

ASM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)asm/
ASM_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_SOURCES_LIST))
ASM_OBJECTS	= $(addprefix $(ASM_OBJECTS_DIRECTORY), $(ASM_OBJECTS_LIST))

# corewar

COREWAR_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/
COREWAR_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_SOURCES_LIST))
COREWAR_OBJECTS	= $(addprefix $(COREWAR_OBJECTS_DIRECTORY), $(COREWAR_OBJECTS_LIST))

all: $(COREWAR_NAME) $(ASM_NAME)

FORCE:		;

$(FT_PRINTF):	FORCE
	make -C $(FT_PRINTF)

$(COREWAR_NAME): $(FT_PRINTF) $(FT_PRINTF)/libftprintf.a $(COREWAR_OBJECTS_DIRECTORY) $(COREWAR_OBJECTS) $(HEADER)/corewar/*.h
	gcc $(FLAGS) -I $(HEADER)/corewar $(COREWAR_OBJECTS) -lncurses $(FT_PRINTF)/libftprintf.a -o $(COREWAR_NAME)

$(ASM_NAME): $(FT_PRINTF) $(FT_PRINTF)/libftprintf.a $(ASM_OBJECTS_DIRECTORY) $(ASM_OBJECTS) $(HEADER)/asm/*.h
	gcc $(FLAGS) -I $(HEADER)/asm $(ASM_OBJECTS) $(FT_PRINTF)/libftprintf.a -g -o $(ASM_NAME)

$(COREWAR_OBJECTS_DIRECTORY):
	mkdir -p $(COREWAR_OBJECTS_DIRECTORY)

$(ASM_OBJECTS_DIRECTORY):
	mkdir -p $(ASM_OBJECTS_DIRECTORY)

$(COREWAR_OBJECTS_DIRECTORY)%.o : $(COREWAR_SOURCES_DIRECTORY)%.c
	gcc $(FLAGS) -c -I $(HEADER)/corewar  $< -o $@

$(ASM_OBJECTS_DIRECTORY)%.o : $(ASM_SOURCES_DIRECTORY)%.c
	gcc $(FLAGS) -c -I $(HEADER)/asm $< -o $@

clean:
	make -C $(FT_PRINTF) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	make -C $(FT_PRINTF) fclean
	rm -f $(ASM_NAME)
	rm -f $(COREWAR_NAME)

re:
	make fclean
	make all
