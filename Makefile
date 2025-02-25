# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:42:49 by gpetit            #+#    #+#              #
#    Updated: 2021/05/26 11:25:01 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = clang

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -Iincludes

LIBFT = -Llibft -lft -ltermcap

SRCS = $(addprefix srcs/, main.c input/read_input.c lexer/lexer.c lexer/quotes.c lexer/parser.c lexer/count.c lexer/initialisation.c\
	lexer/nodes.c lexer/tokens.c lexer/variables.c lexer/odd_chars.c free/free_datas.c free/free_tree.c free/free.c \
	ast/parents.c ast/exec_tree.c ast/exec_builtin.c ast/exec_binary.c ast/redirection_node.c ast/tree.c ast/semicolon_node.c ast/pipe_node.c \
	lexer/arguments.c errors/errors.c builtins/echo.c builtins/cd.c builtins/env.c builtins/env_shell_lvl.c builtins/env_shell_lvl_2.c builtins/pwd.c \
	builtins/exit.c builtins/unset.c builtins/hidden.c grammar/pipe.c \
	grammar/semicolon.c grammar/redirection.c grammar/arguments.c history/init_history.c \
	history/update_history.c history/browse_history.c history/browse_up_history.c history/browse_down_history.c history/save_history.c \
	signals/signals.c termcaps/ctrl_d.c termcaps/termcaps.c prompt/display.c\
	termcaps/termcaps_utils.c termcaps/termcaps_scroll.c termcaps/termcaps_cursor.c \
	termcaps/termcaps_backspace.c termcaps/termcaps_add_char.c \
	termcaps/termcaps_cursor_move_up.c termcaps/termcaps_words_move.c \
	termcaps/termcaps_backspace_middle_line.c termcaps/termcaps_backspace_middle_line2.c \
	variables/replace_variables.c variables/update_arguments.c variables/update_variables.c \
	builtins/env_utils.c termcaps/termcaps_cursor_move_down.c builtins/cd_actualize_env.c \
	builtins/export.c builtins/echo_var.c builtins/export_list_actualization.c builtins/export_list_actualization_2.c \
	builtins/export_args_conformity.c builtins/export_printer.c ast/exec_binary_input_tabs.c \
	grammar/pipe_utils.c input/line_creation.c input/line_creation_2.c)


OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

cleandb:
	rm -f DEBUG_str DEBUG_sequence DEBUG_termcaps

re: fclean $(NAME)
