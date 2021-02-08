/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:47:16 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 03:14:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	Move prefix when zero padding a prefixed number with zeros.
*/

static int			pf_move_prefix(t_printf *p, char *s)
{
	size_t		i;
	size_t		r;

	i = 0;
	r = 0;
	while (!(s_chr("+-xb", s[i])) && s[i])
		i++;
	if (p->sign == -1 &&  s[i] == '-' && s[0] == '0' && chk(g_flags, SIGNED))
		s_swp(&s[i], &s[0]);
	else if (p->sign == 1 && s[i] == '+' && s[0] == '0' && chk(g_flags, PLUS))
		s_swp(&s[i], &s[0]);
	else if ((asr(HASH | X) || chk(g_flags, P)) && s[i] == 'x' && s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (asr(HASH | B) && s[i] == 'b' && s[0] == '0')
		s_swp(&s[i], &s[1]);
	return (r);
}

/*
**	Set all flags in the global `g_flags` variable.
*/

void				pf_set_flags(t_printf *p)
{
	g_flags = 0;
	g_flags = f_scan("bcdefiopsux%-#+. ", p->arg_str, g_flags);
	g_flags = s_str(p->arg_str, "L") ? set(g_flags, LLL) : g_flags;
	g_flags = s_str(p->arg_str, "ll") && !chk(g_flags, LLL) ? set(g_flags, LL) : g_flags;
	g_flags = s_str(p->arg_str, "l") && !chk(g_flags, LLL | LL) ? set(g_flags, L) : g_flags;
	g_flags = s_str(p->arg_str, "hh") ? set(g_flags, HH) : g_flags;
	g_flags = s_str(p->arg_str, "h") && !chk(g_flags, HH) ? set(g_flags, H) : g_flags;
	g_flags = chk(g_flags, C) ? set(g_flags, CHAR) : g_flags;
	g_flags = chk(g_flags, (D | I)) ? set(g_flags, INT) : g_flags;
	g_flags = chk(g_flags, (B | O | U | X)) ? set(g_flags, UINT) : g_flags;
	g_flags = chk(g_flags, (E | F)) ? set(g_flags, DBL) : g_flags;
	g_flags = chk(g_flags, P) ? set(g_flags, PTR) : g_flags;
	g_flags = chk(g_flags, S) ? set(g_flags, PTR) : g_flags;
	g_flags = asr(DBL | LLL) ? set(g_flags, LDBL) - DBL : g_flags;
	g_flags = asr(INT | LL) ? set(g_flags, LLONG) - INT : g_flags;
	g_flags = asr(UINT | LL) ? set(g_flags, ULLONG) - UINT : g_flags;
	g_flags = asr(CHAR | L) ? set(g_flags, INT) - CHAR : g_flags;
	g_flags = asr(INT | L) ? set(g_flags, LONG) - INT : g_flags;
	g_flags = asr(UINT | L) ? set(g_flags, ULONG) - UINT : g_flags;
	g_flags = asr(INT | HH) ? set(g_flags, CHAR) - INT : g_flags;
	g_flags = asr(UINT | HH) ? set(g_flags, UCHAR) - UINT : g_flags;
	g_flags = asr(INT | H) ? set(g_flags, SHORT) - INT : g_flags;
	g_flags = asr(UINT | H) ? set(g_flags, USHORT) - UINT : g_flags;
}

/*
**	Delist arguments according to their respective types from the argument list.
*/

void				pf_delist(t_printf *p)
{
	p->args.intmax = chk(g_flags, INT) ? va_arg(p->arg, int) : p->args.intmax;
	p->args.intmax = chk(g_flags, LONG) ? va_arg(p->arg, long) : p->args.intmax;
	p->args.intmax = chk(g_flags, LLONG) ? va_arg(p->arg, long long) : p->args.intmax;
	p->args.intmax = chk(g_flags, SHORT) ? (short)va_arg(p->arg, int) : p->args.intmax;
	p->args.intmax = chk(g_flags, CHAR) ? (signed char)va_arg(p->arg, int) : p->args.intmax;
	p->args.intmax = chk(g_flags, UINT) ? va_arg(p->arg, unsigned int) : p->args.intmax;
	p->args.intmax = chk(g_flags, ULONG) ? va_arg(p->arg, unsigned long) : p->args.intmax;
	p->args.intmax = chk(g_flags, ULLONG) ? va_arg(p->arg, unsigned long long) : p->args.intmax;
	p->args.intmax = chk(g_flags, USHORT) ? (unsigned short)va_arg(p->arg, int) : p->args.intmax;
	p->args.intmax = chk(g_flags, UCHAR) ? (unsigned char)va_arg(p->arg, int) : p->args.intmax;
	p->args.ldbl = chk(g_flags, DBL) ? va_arg(p->arg, double) : p->args.ldbl;
	p->args.ldbl = chk(g_flags, LDBL) ? va_arg(p->arg, long double) : p->args.ldbl;
	p->args.ptr = chk(g_flags, PTR) ? va_arg(p->arg, void *) : p->args.ptr;
}

/*
**	Convert arguments to string format.
*/

void				pf_convert(t_printf *p, size_t i)
{
	while (s_chr("0-#+ ", p->arg_str[i]))
		i++;
	g_flags = p->arg_str[i - 1] == '0' ? set(g_flags, ZERO) : g_flags;
	p->w = c_atoi(p->arg_str);
	p->p = chk(g_flags, DOT) ? c_atoi(s_chr(p->arg_str, '.')) : 0;
	p->p = (chk(g_flags, F | E) && !chk(g_flags, DOT) && !p->p) ? 6 : p->p;
	p->sign = chk(g_flags, LDBL | DBL) ? m_fsign(p->args.ldbl) : p->sign;
	p->sign = chk(g_flags, INT | LONG | LLONG | SHORT | CHAR) ? m_sign(p->args.intmax) : p->sign;
	p->sign = chk(g_flags, UINT | ULONG | ULLONG | USHORT | UCHAR) ? m_sign(p->args.intmax) : p->sign;
	p->out = chk(g_flags, F) ? c_float(p->args.ldbl, p->p) : p->out;
	p->out = chk(g_flags, E) ? c_float(p->args.ldbl, p->p) : p->out;
	p->out = chk(g_flags, D | I | U) ? c_itoa_base(p->args.intmax, 10) : p->out;
	p->out = chk(g_flags, B) ? c_itoa_base(p->args.intmax, 2) : p->out;
	p->out = chk(g_flags, C) ? s_dup((char *)&p->args.intmax) : p->out;
	p->out = chk(g_flags, O) ? c_itoa_base(p->args.intmax, 8) : p->out;
	p->out = chk(g_flags, X | P) ? c_itoa_base(p->args.intmax, 16) : p->out;
	p->out = chk(g_flags, S) && p->args.ptr ? s_dup((char *)p->args.ptr) : p->out;
	p->out = chk(g_flags, S) && !p->args.ptr ? s_dup("(null)") : p->out;
	p->out = chk(g_flags, ESC) ? s_dup("%") : p->out;
}
/*
**	Set padding and prefix of the argument.
*/
void				pf_padding(t_printf *p, char *pre)
{
	pre = chk(g_flags, F | E | I | D) && p->sign == -1 ? s_dup("-") : pre;
	pre = chk(g_flags, PLUS) && chk(g_flags, F | E | I | D) && p->sign >= 0 ? s_dup("+") : pre;
	pre = chk(g_flags, SPACE) && chk(g_flags, F | D) ? s_dup(" ") : pre;
	pre = asr(HASH | X) && p->sign ? s_dup("0x") : pre;
	pre = chk(g_flags, P) ? s_dup("0x") : pre;
	pre = asr(HASH | B) ? s_dup("0b") : pre;
	pre = asr(HASH | O) && p->p < (int)s_len(p->out) + 1 ? s_dup("0") : pre;
	p->p += s_len(pre);
	p->out = s_join_free(pre, p->out, 3);
	p->out = chk(g_flags, S | C | ESC) ? p->out : s_fill(p->out, p->p, "0");
	p->out = chk(g_flags, S | C | ESC) && p->p ? s_cut(p->out, p->p) : p->out;
	pf_move_prefix(p, p->out);
	if (asr(LEFT | ZERO) && !chk(g_flags, S | C | ESC | DOT))
		p->out = s_fill(p->out, p->w, "0-");
	else if (chk(g_flags, ZERO) && (chk(g_flags, F | E) || !chk(g_flags, DOT)))
		p->out = s_fill(p->out, p->w, "0");
	else if (chk(g_flags, LEFT))
		p->out = s_fill(p->out, p->w, "-");
	else
		p->out = s_fill(p->out, p->w, "");
	pf_move_prefix(p, p->out);
	if (is_upper(p->type))
		s_iter(&p->out, c_toupper);
}
