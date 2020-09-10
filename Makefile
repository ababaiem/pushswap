# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 19:26:35 by ababaie-          #+#    #+#              #
#    Updated: 2020/09/10 19:57:45 by ababaie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB 	= ./libft/libft.a
FLAGS 	= -Wall -Werror -Wextra

PNAME 	= push_swap
CNAME	= checker

CSRC	= checker.c stack_ops.c do_op.c push_pop.c stack_helper.c validate.c \
	  validate_helpers.c $(LIB)
PSRC 	= push_swap.c push_pop.c sort.c sort_20.c stack_ops.c stack_helper.c \
	  do_op.c validate.c sort_helper_functions.c validate_helpers.c $(LIB)

all: $(LIB) $(CNAME) $(PNAME)

$(LIB):
	@make -C ./libft

$(CNAME):
	@gcc $(FLAGS) $(CSRC) -o $(CNAME)

$(PNAME):
	@gcc $(FLAGS) $(PSRC) -o $(PNAME)

clean: 
	@rm -rf $(PNAME) $(CNAME)

fclean: clean
	@make -C ./libft fclean

re: fclean all
