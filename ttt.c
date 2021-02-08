/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:19:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 01:09:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <math.h>
// # define LEFT 0X1000
// # define HASH 0X2000
// # define PLUS 0X4000
// # define DOT 0X8000
// # define SPACE 0X10000
// # define ZERO 0X20000

char	*format = "bcdefiopsux%-#+. ";

int64_t			m_ipow(int64_t base, int64_t exp)
{
	int64_t		tmp;
	size_t		i;

	i = 0;
	tmp = base;
	if (base == 0 && exp == 0)
		return (1);
	else if (base == 0)
		return (0);
	else if (exp == 0)
		return (1);
	while (i < exp - 1)
	{
		tmp *= base;
		i++;
	}
	return (tmp);
}

size_t			match_flags(char *id, char *arg_str, size_t flags)
{
	size_t		i;
	size_t		j;
	size_t		ret;

	i = 0;
	j = 0;
	while (arg_str[i])
	{
		if (s_chr(id, arg_str[i]))
		{
			while (id[j] != arg_str[i])
				j++;
			ret = (size_t)m_ipow(2, j);
			flags |= ret;
			j = 0;
		}
		i++;
	}
	return (flags);
}

unsigned char	get_flag_symbol(char *flag_order, size_t flag)
{
	return (flag_order[(size_t)m_log((double)flag)]);
}

int main(void)
{
	// printf("%d\n", B);
	// printf("%d\n", F);
	// size_t flags =  0;
	// size_t width =  0;
	// size_t prec =  0;
	// char	*args = "-#030.20Lf";

	// flags = cchr(format, args, flags);
	// width = c_atoi(args);
	// prec = flags & DOT ? c_atoi(s_chr(args, '.')) : 0;
	// ft_printf("%.32b\n", flags);
	// ft_printf("%d\n", width);
	// ft_printf("%d\n", prec);
	// printf("%d\n", X);
	// printf("%d\n", (int)log2(X));
	printf("%c\n", get_flag_symbol(format, X));
	// printf("%f\n", m_sqrt(cchr("nmkp")));
}

// static void			pf_set_flags(t_printf *p, char type)
// {
// 	g_flags = 0;
// 	p->w = 0;
// 	p->p = 0;
// 	g_flags = chr(p->arg_str, "-") ? set(LEFT) : g_flags;
// 	g_flags = chr(p->arg_str, "#") ? set(HASH) : g_flags;
// 	g_flags = chr(p->arg_str, "+") ? set(PLUS) : g_flags;
// 	g_flags = chr(p->arg_str, ".") ? set(DOT) : g_flags;
// 	g_flags = chr(p->arg_str, " ") ? set(SPACE) : g_flags;
// 	g_flags = type == 'b' ? set(B) : g_flags;
// 	g_flags = type == 'c' ? set(C) : g_flags;
// 	g_flags = type == 'd' ? set(D) : g_flags;
// 	g_flags = type == 'e' ? set(E) : g_flags;
// 	g_flags = type == 'f' ? set(F) : g_flags;
// 	g_flags = type == 'i' ? set(I) : g_flags;
// 	g_flags = type == 'o' ? set(O) : g_flags;
// 	g_flags = type == 'p' ? set(P) : g_flags;
// 	g_flags = type == 's' ? set(S) : g_flags;
// 	g_flags = type == 'u' ? set(U) : g_flags;
// 	g_flags = type == 'x' ? set(X) : g_flags;
// 	g_flags = type == '%' ? set(ESC) : g_flags;
// 	g_flags = chr(p->arg_str, "L") ? set(LLL) : g_flags;
// 	g_flags = chr(p->arg_str, "ll") && !chk(LLL) ? set(LL) : g_flags;
// 	g_flags = chr(p->arg_str, "l") && !chk(LLL | LL) ? set(L) : g_flags;
// 	g_flags = chr(p->arg_str, "hh") ? set(HH) : g_flags;
// 	g_flags = chr(p->arg_str, "h") && !chk(HH) ? set(H) : g_flags;
// }

// static void			pf_set_size(void)
// {
// 	g_flags = chk(C) ? set(CHAR) : g_flags;
// 	g_flags = chk((D | I)) ? set(INT) : g_flags;
// 	g_flags = chk((B | O | U | X)) ? set(UINT) : g_flags;
// 	g_flags = chk((E | F)) ? set(DBL) : g_flags;
// 	g_flags = chk(P) ? set(PTR) : g_flags;
// 	g_flags = chk(S) ? set(PTR) : g_flags;
// 	g_flags = asr(DBL | LLL) ? set(LDBL) - DBL : g_flags;
// 	g_flags = asr(INT | LL) ? set(LLONG) - INT : g_flags;
// 	g_flags = asr(UINT | LL) ? set(ULLONG) - UINT : g_flags;
// 	g_flags = asr(CHAR | L) ? set(INT) - CHAR : g_flags;
// 	g_flags = asr(INT | L) ? set(LONG) - INT : g_flags;
// 	g_flags = asr(UINT | L) ? set(ULONG) - UINT : g_flags;
// 	g_flags = asr(INT | HH) ? set(CHAR) - INT : g_flags;
// 	g_flags = asr(UINT | HH) ? set(UCHAR) - UINT : g_flags;
// 	g_flags = asr(INT | H) ? set(SHORT) - INT : g_flags;
// 	g_flags = asr(UINT | H) ? set(USHORT) - UINT : g_flags;
// }
