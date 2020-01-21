# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 16:50:37 by jnovotny          #+#    #+#              #
#    Updated: 2020/01/21 14:42:47 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_GREEN = \033[1;32m
C_BLUE = \033[1;34m
C_L_BLUE = \033[1;34m
C_WHITE = \033[1;37m
C_RES = \033[0m

NAME = push_swap
CHECK = checker

LIB = ../printf/libft.a

FTS =	check_sort.c \
		clear_list.c \
		cmd_man.c \
		cmd_man2.c \
		cmd_parse.c \
		cmd_parse2.c \
		cmd_parse3.c \
		cmp_control.c \
		exit.c \
		ft_getflags_arg.c \
		list_man.c \
		list_man2.c \
		list_man3.c \
		list_man4.c \
		list_print.c \
		ps_init.c \
		ps_iterquicksort.c \
		ps_operations.c \
		ps_operations2.c \
		ps_operations3.c \
		ps_qs_tools.c \
		ps_qs_tools2.c \
		ps_sortop3.c \
		ps_tools.c \
		push_swap_ops.c \
		push_swap_iterquicksort.c \
		read_numbers.c \
		vfx_colors.c \
		vfx_draw_env.c \
		vfx_draw_graph.c \
		vfx_draw_graph2.c \
		vfx_draw_playback.c \
		vfx_draw_text.c \
		vfx_engine.c \
		vfx_environment.c \
		visualize.c

L_FTS =	check_sort.c \
		clear_list.c \
		cmd_man.c \
		cmd_man2.c \
		cmd_parse.c \
		cmd_parse2.c \
		cmd_parse3.c \
		cmp_control.c \
		exit.c \
		ft_getflags_arg.c \
		list_man.c \
		list_man2.c \
		list_man3.c \
		list_man4.c \
		list_print.c \
		ps_iterquicksort.c \
		ps_tools.c \
		push_swap_insertsort.c \
		push_swap_merge.c \
		push_swap_ops.c \
		push_swap_iterquicksort.c \
		read_numbers.c

FTO = $(FTS.c=.o)

LIB_I = ../printf/includes/

I_DIR = ./includes/
S_DIR = ./srcs/
O_DIR = ./objs/

SRCS = $(addprefix $(S_DIR), $(FTS))
L_SRCS = $(addprefix $(S_DIR), $(L_FTS))

PS_M = ./srcs/main_pushswap.c
CH_M = ./srcs/main_checker.c

CFLAGS = -Wall -Werror -Wextra

GRAPHIC = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re libft

all: $(NAME) $(CHECK)

libft:
	# @make -C ./library

$(NAME):
	@gcc -o $(NAME) $(CFLAGS) -I$(I_DIR) -I$(LIB_I) $(LIB) $(SRCS) $(PS_M) $(GRAPHIC)
	@echo "$(C_GREEN)[$(C_BLUE)$(NAME)$(C_GREEN) was compiled]$(C_RES)"

$(CHECK):
	@gcc -o $(CHECK) $(CFLAGS) -I$(I_DIR) -I$(LIB_I) $(LIB) $(SRCS) $(CH_M) $(GRAPHIC)
	@echo "$(C_GREEN)[$(C_BLUE)$(CHECK)$(C_GREEN) was compiled]$(C_RES)"

linux:
	@gcc -o ps_linux $(CFLAGS) -I$(I_DIR) -I$(LIB_I) $(L_SRCS) $(PS_M) $(LIB)
	@echo "$(C_GREEN)[$(C_BLUE)linux version$(C_GREEN) was compiled (no graphic)]$(C_RES)"

clean:
	# @make clean -C ./library
	@/bin/rm -rf $(O_DIR)
	@echo "$(C_RED)[Objects deleted!]$(C_RES)"

fclean: clean
	# @make fclean -C ./library
	@/bin/rm -f $(NAME) $(CHECK) ps_linux
	@echo "$(C_RED)[Removed $(NAME) and $(CHECK)]$(C_RES)"

re: fclean all