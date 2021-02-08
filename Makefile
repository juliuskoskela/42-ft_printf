# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 22:32:30 by jkoskela          #+#    #+#              #
#    Updated: 2021/02/08 01:55:52 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC_LIST	=	ft_printf.c \
				ft_asprintf.c \
				ft_vasprintf.c \
				utils.c \
				c_float.c \
				pf_core.c \

HEADER		=	inc
FOLDER		=	src
LIBFT 		=	libft

CC			=	clang
CFLAGS 		=	-g -Wall -Wextra -Werror -fPIC
RM			=	rm -f

SRC			=	$(addprefix ${FOLDER}/, ${SRC_LIST})
OBJ			=	${SRC:.c=.o}

all:			${NAME}

$(NAME):		${OBJ}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJ}

test:			${NAME}

				mv eval_tests/test.sh test.sh
				bash test.sh
				mv test.sh eval_tests/test.sh

%.o: %.
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJ}
				@make clean -C $(LIBFT)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
				rm -rf a.out.dSYM

tclean:			fclean
				@rm usr.txt
				@rm lib.txt
				@rm diff.txt
				@rm a.out
				@rm additional_tests.txt

re:				fclean all

.PHONY: 		all test tclean fclean clean re
