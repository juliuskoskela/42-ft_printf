/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:14:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 05:05:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/inc/libft.h"
# include <stdarg.h>
# include <ctype.h>
# define B 0X1
# define C 0X2
# define D 0X4
# define E 0X8
# define F 0X10
# define I 0X20
# define O 0X40
# define P 0X80
# define S 0X100
# define U 0X200
# define X 0X400
# define ESC 0X800
# define LEFT 0X1000
# define HASH 0X2000
# define PLUS 0X4000
# define DOT 0X8000
# define SPACE 0X10000
# define ZERO 0X20000
# define INT 0X40000
# define UINT 0X80000
# define LONG  0X100000
# define ULONG 0X200000
# define LLONG 0X400000
# define ULLONG 0X800000
# define SHORT 0X1000000
# define USHORT 0X2000000
# define CHAR 0X4000000
# define UCHAR 0X8000000
# define DBL 0X10000000
# define LDBL 0X20000000
# define PTR 0X40000000
# define L 0X80000000
# define LL 0X100000000
# define LLL 0X200000000
# define H 0X400000000
# define HH 0X800000000
# define SIZE_MASK 0XFFFC0000
# define SPEC_MASK 0XFFFC0FFF
# define TYPE_MASK 0XFFFFF000
# define SIGNED 0X5540000
# define UNSIGNED 0XAA80000
# define FLOAT 0X30000000

typedef union		s_args
{
	intmax_t		i;
	long double		d;
	void			*p;
}					t_args;

typedef struct		s_printf
{
	size_t			f;
	va_list			ap;
	t_args			a;
	char			*flags;
	char			*in;
	char			*out;
	int				w;
	int				p;
	int				sign;
	int				type;
}					t_printf;

int					ft_printf(const char *format, ...);
int					ft_asprintf(char **out, const char *format, ...);
int					ft_vasprintf(char **out, const char *format, va_list ap);
void				pf_set_flags(t_printf *p);
void				pf_delist(t_printf *p);
void				pf_convert(t_printf *p, size_t i);
void				pf_padding(t_printf *p, char *pre);
char				*pf_treat_float(long double nbr, int prec, size_t flags);

#endif
