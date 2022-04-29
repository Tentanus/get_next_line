# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/19 20:19:24 by mweverli      #+#    #+#                  #
#    Updated: 2022/04/22 20:37:05 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#VAR

CC		=	gcc
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
	./$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFL) -c $< -o $@

clean:
	@mkdir -p $(OBJ_DIR)
	rm -r $(OBJ_DIR)

fclean: clean
	rm ./$(NAME)

re: fclean test

