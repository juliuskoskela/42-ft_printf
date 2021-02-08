/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:47:16 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 20:08:02 by jkoskela         ###   ########.fr       */
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
	while (!(s_chr(" +-xb", s[i])) && s[i])
		i++;
	if (p->sign == -1 &&  s[i] == '-' && s[0] == '0' && f_c(p->f, SIGNED))
		s_swp(&s[i], &s[0]);
	else if (p->sign == 1 && s[i] == '+' && s[0] == '0' && f_c(p->f, PLUS))
		s_swp(&s[i], &s[0]);
	else if ((f_a(p->f, HASH | X) || f_c(p->f, P)) && s[i] == 'x' && s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (f_a(p->f, HASH | B) && s[i] == 'b' && s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (f_a(p->f, SPACE) && s[i] == ' ' && s[0] == '0')
		s_swp(&s[i], &s[0]);
	return (r);
}

/*
**	Set all flags p->f.
*/

void				pf_set_flags(t_printf *p)
{
	p->f = f_scan("bcdefiopsux%-#+. ", p->flags);
	p->f = s_str(p->flags, "L") ? f_s(p->f, LLL) : p->f;
	p->f = s_str(p->flags, "ll") && !f_c(p->f, LLL) ? f_s(p->f, LL) : p->f;
	p->f = s_str(p->flags, "l") && !f_c(p->f, LLL | LL) ? f_s(p->f, L) : p->f;
	p->f = s_str(p->flags, "hh") ? f_s(p->f, HH) : p->f;
	p->f = s_str(p->flags, "h") && !f_c(p->f, HH) ? f_s(p->f, H) : p->f;
	p->f = f_c(p->f, C) ? f_s(p->f, CHAR) : p->f;
	p->f = f_c(p->f, (D | I)) ? f_s(p->f, INT) : p->f;
	p->f = f_c(p->f, (B | O | U | X)) ? f_s(p->f, UINT) : p->f;
	p->f = f_c(p->f, (E | F)) ? f_s(p->f, DBL) : p->f;
	p->f = f_c(p->f, P) ? f_s(p->f, PTR) : p->f;
	p->f = f_c(p->f, S) ? f_s(p->f, PTR) : p->f;
	p->f = f_a(p->f, DBL | LLL) ? f_s(p->f, LDBL) - DBL : p->f;
	p->f = f_a(p->f, INT | LL) ? f_s(p->f, LLONG) - INT : p->f;
	p->f = f_a(p->f, UINT | LL) ? f_s(p->f, ULLONG) - UINT : p->f;
	p->f = f_a(p->f, CHAR | L) ? f_s(p->f, INT) - CHAR : p->f;
	p->f = f_a(p->f, INT | L) ? f_s(p->f, LONG) - INT : p->f;
	p->f = f_a(p->f, UINT | L) ? f_s(p->f, ULONG) - UINT : p->f;
	p->f = f_a(p->f, INT | HH) ? f_s(p->f, CHAR) - INT : p->f;
	p->f = f_a(p->f, UINT | HH) ? f_s(p->f, UCHAR) - UINT : p->f;
	p->f = f_a(p->f, INT | H) ? f_s(p->f, SHORT) - INT : p->f;
	p->f = f_a(p->f, UINT | H) ? f_s(p->f, USHORT) - UINT : p->f;
}

/*
**	Delist arguments according to their respective types from the argument list.
*/

void				pf_delist(t_printf *p)
{
	p->a.i = f_c(p->f, INT) ? va_arg(p->ap, int) : p->a.i;
	p->a.i = f_c(p->f, LONG) ? va_arg(p->ap, long) : p->a.i;
	p->a.i = f_c(p->f, LLONG) ? va_arg(p->ap, long long) : p->a.i;
	p->a.i = f_c(p->f, SHORT) ? (short)va_arg(p->ap, int) : p->a.i;
	p->a.i = f_c(p->f, CHAR) ? (signed char)va_arg(p->ap, int) : p->a.i;
	p->a.i = f_c(p->f, UINT) ? va_arg(p->ap, unsigned int) : p->a.i;
	p->a.i = f_c(p->f, ULONG) ? va_arg(p->ap, unsigned long) : p->a.i;
	p->a.i = f_c(p->f, ULLONG) ? va_arg(p->ap, unsigned long long) : p->a.i;
	p->a.i = f_c(p->f, USHORT) ? (unsigned short)va_arg(p->ap, int) : p->a.i;
	p->a.i = f_c(p->f, UCHAR) ? (unsigned char)va_arg(p->ap, int) : p->a.i;
	p->a.d = f_c(p->f, DBL) ? va_arg(p->ap, double) : p->a.d;
	p->a.d = f_c(p->f, LDBL) ? va_arg(p->ap, long double) : p->a.d;
	p->a.p = f_c(p->f, PTR) ? va_arg(p->ap, void *) : p->a.p;
}

/*
**	Convert arguments to string format.
*/

void				pf_convert(t_printf *p, size_t i)
{
	while (s_chr("0-#+ ", p->flags[i]))
		i++;
	p->f = p->flags[i - 1] == '0' ? f_s(p->f, ZERO) : p->f;
	p->w = c_atoi(p->flags);
	p->p = c_atoi(s_chr(p->flags, '.'));
	p->p = (f_c(p->f, FLOAT) && !f_c(p->f, DOT) && !p->p) ? 6 : p->p;
	p->sign = f_c(p->f, FLOAT) ? m_fsign(p->a.d) : p->sign;
	p->sign = f_c(p->f, SIGNED) ? m_sign(p->a.i) : p->sign;
	p->sign = f_c(p->f, UNSIGNED) ? m_sign(p->a.i) : p->sign;
	p->out = f_c(p->f, FLOAT) ? pf_treat_float(p->a.d, p->p, p->f) : p->out;
	p->out = f_c(p->f, B) ? c_itoa_base(p->a.i, 2) : p->out;
	p->out = f_c(p->f, O) ? c_itoa_base(p->a.i, 8) : p->out;
	p->out = f_c(p->f, D | I | U) ? c_itoa_base(p->a.i, 10) : p->out;
	p->out = f_c(p->f, X | P) ? c_itoa_base(p->a.i, 16) : p->out;
	p->out = f_c(p->f, C) ? s_dup((char *)&p->a.i) : p->out;
	p->out = f_c(p->f, S) && p->a.p ? s_dup((char *)p->a.p) : p->out;
	p->out = f_c(p->f, S) && !p->a.p ? s_dup("(null)") : p->out;
	p->out = f_c(p->f, ESC) ? s_dup("%") : p->out;
}

/*
**	Set padding and prefix of the argument.
*/

void				pf_padding(t_printf *p, char *pre)
{
	pre = f_c(p->f, F | E | I | D) && p->sign == -1 ? s_dup("-") : pre;
	pre = f_c(p->f, PLUS) && f_c(p->f, F | E | I | D) && p->sign >= 0 ? s_dup("+") : pre;
	pre = f_c(p->f, SPACE) && f_c(p->f, F | D) && !f_c(p->f, PLUS) && p->sign != -1 ? s_dup(" ") : pre;
	pre = f_a(p->f, HASH | X) && p->sign ? s_dup("0x") : pre;
	pre = f_c(p->f, P) ? s_dup("0x") : pre;
	pre = f_a(p->f, HASH | B) ? s_dup("0b") : pre;
	pre = f_a(p->f, HASH | O) && p->p < (int)s_len(p->out) + 1 ? s_dup("0") : pre;
	p->p += s_len(pre);
	p->out = s_join_free(pre, p->out, 3);
	p->out = f_c(p->f, S | C | ESC) ? p->out : s_fill(p->out, p->p, "0");
	p->out = f_c(p->f, S | C | ESC) && p->p ? s_cut(p->out, p->p) : p->out;
	pf_move_prefix(p, p->out);
	if (f_a(p->f, LEFT | ZERO) && !f_c(p->f, S | C | ESC | DOT))
		p->out = s_fill(p->out, p->w, "0-");
	else if (f_c(p->f, ZERO) && (f_c(p->f, F | E) || !f_c(p->f, DOT)))
		p->out = s_fill(p->out, p->w, "0");
	else if (f_c(p->f, LEFT))
		p->out = s_fill(p->out, p->w, "-");
	else
		p->out = s_fill(p->out, p->w, "");
	pf_move_prefix(p, p->out);
	if (is_upper(p->type))
		s_iter(&p->out, c_toupper);
}
