# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/19 20:19:24 by mweverli      #+#    #+#                  #
#    Updated: 2022/04/30 20:42:05 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#VAR

CC		=	gcc
CLG		=	clang
CFL		=	-Wall -Werror -Wextra
NAME	=	get_next_output
OBJ_DIR	=	./OBJ

SRC	=	main.c \
		get_next_line.c \
		get_next_line_utils.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

#COM
test: $(OBJ)
	$(CC) $(CFL) -o $(NAME) $^
#	./$(NAME)

db_test: $(OBJ)
	$(CC) $(CFL) -g -o $(NAME) $^
	lldb ./$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFL) -g -c $< -o $@

clean:
	@mkdir -p $(OBJ_DIR)
	rm -r $(OBJ_DIR)

fclean: clean
	rm ./$(NAME)

re: fclean test

