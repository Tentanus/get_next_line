# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/19 20:19:24 by mweverli      #+#    #+#                  #
#    Updated: 2022/08/01 21:22:08 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	get_next_line.a

OBJ_DIR		:=	./OBJ
SRC_DIR		:=	./src
INC_DIR		:=	./include

SRC			:=	$(shell ls src/)
OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
RESET	:= \033[0m

#============= COMPILATION ==============#

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra
CFL_DB		:=	-Wall -Werror -Wextra -g -fsanitize=address

HEADER		:=	-I ./include

ifdef DB
COMPILE		:=	$(CC) $(CFL_DB)
else
COMPILE		:=	$(CC) $(CFL)
endif

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^ 
	@echo "$(GREEN)$(BOLD)FINISHED COMPILING: $(NAME)(RESET)"

test_db: clean
	@make $(NAME) DB=1

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(COMPILE) -o $@ -c $< $(HEADER)
	@echo "$(GREEN)COMPILING: $(notdir $<) $(RESET)"

clean:
	@echo "$(RED)$(BOLD)Cleaning Get_Next_Line$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean re test_db

.DEFAULT_GOAL := all

FORCE:

test_var: $(FORCE)
	$(SRC)
