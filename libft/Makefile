# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/02/05 19:58:56 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			?=	gcc
FLAGS		=	-g -Wall -Wextra -Werror -O3 -D FULL_LIBFT

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-32-$(LEN_NAME)"|bc)

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE =	bits/b_atonb.c \
			bits/b_checknth.c \
			bits/b_fldclear.c \
			bits/b_fldcmp.c \
			bits/b_fldcol.c \
			bits/b_flddel.c \
			bits/b_flddup.c \
			bits/b_fldfill.c \
			bits/b_fldinit.c \
			bits/b_fldminus.c \
			bits/b_fldmovedown.c \
			bits/b_fldmoveleft.c \
			bits/b_fldmoveright.c \
			bits/b_fldmoveup.c \
			bits/b_fldnew.c \
			bits/b_fldoverlap.c \
			bits/b_fldplus.c \
			bits/b_fldprint.c \
			bits/b_fldsize.c \
			bits/b_highest.c \
			bits/b_lowest.c \
			conversions/c_atof.c \
			conversions/c_atoi.c \
			conversions/c_atoi_base.c \
			conversions/c_bitoa.c \
			conversions/c_itoa.c \
			conversions/c_itoa_base.c \
			conversions/c_tolower.c \
			conversions/c_toupper.c \
			conversions/c_ftoa.c \
			conversions/c_ftoe.c \
			dlist/dl_del_last.c \
			dlist/dl_del_list.c \
			dlist/dl_del_node.c \
			dlist/dl_del_node_at.c \
			dlist/dl_get_last.c \
			dlist/dl_join.c \
			dlist/dl_len.c \
			dlist/dl_print.c \
			dlist/dl_putafter.c \
			dlist/dl_putbefore.c \
			dlist/dl_putfirst.c \
			dlist/dl_putlast.c \
			dlist/dl_rotate.c \
			error/error.c \
			fd/fd_addchar.c \
			fd/fd_addendl.c \
			fd/fd_addnbr.c \
			fd/fd_addstr.c \
			fd/fd_readline.c \
			istrue/is_alnum.c \
			istrue/is_alpha.c \
			istrue/is_ascii.c \
			istrue/is_digit.c \
			istrue/is_lower.c \
			istrue/is_neg.c \
			istrue/is_print.c \
			istrue/is_upper.c \
			istrue/is_wspace.c \
			istrue/is_numeric.c \
			stack/st_push.c \
			stack/st_pop.c \
			math/m_rad.c \
			math/m_dgr.c \
			math/m_fabs.c \
			math/m_flabs.c \
			math/m_fac.c \
			math/m_intlen.c \
			math/m_log.c \
			math/m_nextprime.c \
			math/m_pow.c \
			math/m_prime.c \
			math/m_primefac.c \
			math/m_sin.c \
			math/m_cos.c \
			math/m_sqrt.c \
			math/m_dcnt.c \
			math/m_ceil.c \
			math/m_floor.c \
			math/m_modf.c \
			math/m_sign.c \
			math/m_fsign.c \
			math/m_abs.c \
			print/p_bits.c \
			print/p_char.c \
			print/p_endl.c \
			print/p_nbr.c \
			print/p_str.c \
			print/p_dlist_s.c \
			strings/s_cat.c \
			strings/s_cdup.c \
			strings/s_chr.c \
			strings/s_clr.c \
			strings/s_cmp.c \
			strings/s_cpy.c \
			strings/s_csub.c \
			strings/s_del.c \
			strings/s_dup.c \
			strings/s_equ.c \
			strings/s_iter.c \
			strings/s_iteri.c \
			strings/s_join.c \
			strings/s_lcat.c \
			strings/s_lcpy.c \
			strings/s_len.c \
			strings/s_lenc.c \
			strings/s_map.c \
			strings/s_mapi.c \
			strings/s_ncat.c \
			strings/s_ncmp.c \
			strings/s_ncpy.c \
			strings/s_ndup.c \
			strings/s_copy.c \
			strings/s_nequ.c \
			strings/s_new.c \
			strings/s_nstr.c \
			strings/s_rchr.c \
			strings/s_rev.c \
			strings/s_split.c \
			strings/s_str.c \
			strings/s_sub.c \
			strings/s_trim.c \
			strings/s_sum.c \
			strings/s_appendc.c \
			strings/s_ctoc.c \
			strings/s_newc.c \
			strings/s_join_free.c \
			strings/s_fill.c \
			strings/s_cut.c \
			void/v_alloc.c \
			void/v_bzero.c \
			void/v_calloc.c \
			void/v_ccpy.c \
			void/v_chr.c \
			void/v_cmp.c \
			void/v_cpy.c \
			void/v_del.c \
			void/v_move.c \
			void/v_set.c \
			graphics/g_sub.c \
			graphics/g_add.c \
			graphics/g_cross.c \
			graphics/g_dot.c \
			graphics/g_mag.c \
			graphics/g_proj.c \
			graphics/g_mult_mtx.c \
			graphics/g_translate.c \
			graphics/g_mult_vct.c \
			graphics/g_rotx.c \
			graphics/g_roty.c \
			graphics/g_rotz.c \
			graphics/g_transpose.c \
			graphics/g_norm.c \
			graphics/g_vct4.c \
			graphics/g_opp.c \
			graphics/g_scale.c \
			graphics/g_print_mtx.c \
			graphics/g_print_vct.c \

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

SHELL 		:=	/bin/bash

all :
	@$(MAKE) -j $(NAME)

$(NAME) :		$(OBJS) Makefile
	@ar rcs $(NAME) $(OBJS)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"

$(DIR) :
	@mkdir -p $@

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c Makefile | $(DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean :
	@if [ -d $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n"; \
	fi;

fclean :		clean
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n"; \
	fi;

re :			fclean
	@$(MAKE) -j $(NAME)

.PHONY :		fclean clean re