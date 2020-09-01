#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2020/09/01 02:21:35 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	push_swap
NAME2		=	checker
DIRSRC		=	src
DIROBJ		=	./depo/
INCLUDE		=	./libft/include/
SUB_MAKE	=	./libft/
INC_LIB		=	-L$(SUB_MAKE) -lft
SRC			=	push_swap.c treatment.c treatment2.c valid_input.c verif.c verif2.c solve.c solve2.c
SRC2		=	checker.c treatment.c treatment2.c valid_input.c verif.c verif2.c solve.c solve2.c
OAUX		=	$(SRC:%=$(DIROBJ)%)
OAUX2		=	$(SRC2:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d) $(OAUX2:.c=.d)
OBJS		=	$(OAUX:.c=.o)
OBJS2		=	$(OAUX2:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

%.o		:		../$(DIRSRC)/%.c
				$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

$(NAME)	:		submake $(OBJS) $(OBJS2)
				@$(ECHO) '> Compiled'
				@$(CC)  -I $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)
				@$(CC)  -I $(INCLUDE) $(CFLAGS) -o $(NAME2) $(OBJS2) $(INC_LIB)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(OBJS2))
				@($(RM) $(DEPS))
				@(cd $(SUB_MAKE) && $(MAKE) clean)
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
				@$(RM) $(NAME)
				@$(RM) $(NAME2)
				@$(ECHO) '> Remove executable'

re		:		fclean all

submake	:
				@(cd $(SUB_MAKE) && $(MAKE))


.PHONY	:		all clean re

-include $(DEPS)
