/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:50:47 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/07 05:07:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*decimal(long double nbr, int prec)
{
	char			*out;

	if (prec > 20)
		out = c_ftoa(nbr, 20);
	else
		out = c_ftoa(nbr, prec);
	if (asr(DOT | HASH) && prec == 0)
		out[s_lenc(out, '.') + 1] = '\0';
	else if (chk(DOT) && prec == 0)
		out[s_lenc(out, '.')] = '\0';
	return (out);
}

static char			*scientific(long double nbr, int prec)
{
	char			*out;
	char			*tmp;
	long double		sign;
	int				i;

	i = 0;
	sign = 1;
	if ((tmp = is_abnormal(nbr)))
		return (tmp);
	if (nbr < 0)
		sign = -1;
	nbr = m_fabs(nbr);
	while (nbr >= 10.0)
	{
		nbr /= 10.0;
		i++;
	}
	nbr = nbr * sign;
	tmp = decimal(nbr, prec);
	out = s_join_free(tmp, "e+0", 1);
	tmp = s_join_free(out, c_itoa_base(i, 10), 3);
	return (tmp);
}

static int			pf_move_prefix(char *s)
{
	size_t		i;
	size_t		r;

	i = 0;
	r = 0;
	while (!(s_chr("+-xb", s[i])) && s[i])
		i++;
	if (g_s == -1 &&  s[i] == '-' && s[0] == '0' && chk(SIGNED))
		swp(&s[i], &s[0]);
	else if (g_s == 1 && s[i] == '+' && s[0] == '0' && chk(PLUS))
		swp(&s[i], &s[0]);
	else if ((asr(HASH | X) || chk(P)) && s[i] == 'x' && s[0] == '0')
		swp(&s[i], &s[1]);
	else if (asr(HASH | B) && s[i] == 'b' && s[0] == '0')
		swp(&s[i], &s[1]);
	return (r);
}

static void			pf_set_flags(char *arg_str, char type)
{
	g_flag = 0;
	g_w = 0;
	g_p = 0;
	g_flag = chr(arg_str, "-") ? set(LEFT) : g_flag;
	g_flag = chr(arg_str, "#") ? set(HASH) : g_flag;
	g_flag = chr(arg_str, "+") ? set(PLUS) : g_flag;
	g_flag = chr(arg_str, ".") ? set(DOT) : g_flag;
	g_flag = chr(arg_str, " ") ? set(SPACE) : g_flag;
	g_flag = type == 'b' ? set(B) : g_flag;
	g_flag = type == 'c' ? set(C) : g_flag;
	g_flag = type == 'd' ? set(D) : g_flag;
	g_flag = type == 'e' ? set(E) : g_flag;
	g_flag = type == 'f' ? set(F) : g_flag;
	g_flag = type == 'i' ? set(I) : g_flag;
	g_flag = type == 'o' ? set(O) : g_flag;
	g_flag = type == 'p' ? set(P) : g_flag;
	g_flag = type == 's' ? set(S) : g_flag;
	g_flag = type == 'u' ? set(U) : g_flag;
	g_flag = type == 'x' ? set(X) : g_flag;
	g_flag = type == '%' ? set(ESC) : g_flag;
	g_flag = chr(arg_str, "L") ? set(LLL) : g_flag;
	g_flag = chr(arg_str, "ll") && !chk(LLL) ? set(LL) : g_flag;
	g_flag = chr(arg_str, "l") && !chk(LLL | LL) ? set(L) : g_flag;
	g_flag = chr(arg_str, "hh") ? set(HH) : g_flag;
	g_flag = chr(arg_str, "h") && !chk(HH) ? set(H) : g_flag;
}

static void			pf_set_size(void)
{
	g_flag = chk(C) ? set(CHAR) : g_flag;
	g_flag = chk((D | I)) ? set(INT) : g_flag;
	g_flag = chk((B | O | U | X)) ? set(UINT) : g_flag;
	g_flag = chk((E | F)) ? set(DBL) : g_flag;
	g_flag = chk(P) ? set(PTR) : g_flag;
	g_flag = chk(S) ? set(PTR) : g_flag;
	g_flag = asr(DBL | LLL) ? set(LDBL) - DBL : g_flag;
	g_flag = asr(INT | LL) ? set(LLONG) - INT : g_flag;
	g_flag = asr(UINT | LL) ? set(ULLONG) - UINT : g_flag;
	g_flag = asr(CHAR | L) ? set(INT) - CHAR : g_flag;
	g_flag = asr(INT | L) ? set(LONG) - INT : g_flag;
	g_flag = asr(UINT | L) ? set(ULONG) - UINT : g_flag;
	g_flag = asr(INT | HH) ? set(CHAR) - INT : g_flag;
	g_flag = asr(UINT | HH) ? set(UCHAR) - UINT : g_flag;
	g_flag = asr(INT | H) ? set(SHORT) - INT : g_flag;
	g_flag = asr(UINT | H) ? set(USHORT) - UINT : g_flag;
}

static void			pf_delist(t_printf *p)
{
	args.intmax = chk(INT) ? va_arg(p->arg, int) : args.intmax;
	args.intmax = chk(LONG) ? va_arg(p->arg, long) : args.intmax;
	args.intmax = chk(LLONG) ? va_arg(p->arg, long long) : args.intmax;
	args.intmax = chk(SHORT) ? (short)va_arg(p->arg, int) : args.intmax;
	args.intmax = chk(CHAR) ? (signed char)va_arg(p->arg, int) : args.intmax;
	args.intmax = chk(UINT) ? va_arg(p->arg, unsigned int) : args.intmax;
	args.intmax = chk(ULONG) ? va_arg(p->arg, unsigned long) : args.intmax;
	args.intmax = chk(ULLONG) ? va_arg(p->arg, unsigned long long) : args.intmax;
	args.intmax = chk(USHORT) ? (unsigned short)va_arg(p->arg, int) : args.intmax;
	args.intmax = chk(UCHAR) ? (unsigned char)va_arg(p->arg, int) : args.intmax;
	args.ldbl = chk(DBL) ? va_arg(p->arg, double) : args.ldbl;
	args.ldbl = chk(LDBL) ? va_arg(p->arg, long double) : args.ldbl;
	args.ptr = chk(PTR) ? va_arg(p->arg, void *) : args.ptr;
}

static void			pf_convert(t_printf *p, size_t i)
{
	while (s_chr("0-#+ ", p->arg_str[i]))
		i++;
	g_flag = p->arg_str[i - 1] == '0' ? set(ZERO) : g_flag;
	g_w = c_atoi(p->arg_str);
	g_p = chk(DOT) ? c_atoi(s_chr(p->arg_str, '.')) : 0;
	g_p = (chk(F | E) && !chk(DOT) && !g_p) ? 6 : g_p;
	g_s = chk(LDBL | DBL) ? m_fsign(args.ldbl) : g_s;
	g_s = chk(INT | LONG | LLONG | SHORT | CHAR) ? m_sign(args.intmax) : g_s;
	g_s = chk(UINT | ULONG | ULLONG | USHORT | UCHAR) ? m_sign(args.intmax) : g_s;
	p->out = chk(F) ? decimal(args.ldbl, g_p) : p->out;
	p->out = chk(D | I | U) ? c_itoa_base(args.intmax, 10) : p->out;
	p->out = chk(E) ? scientific(args.ldbl, g_p) : p->out;
	p->out = chk(B) ? c_itoa_base(args.intmax, 2) : p->out;
	p->out = chk(C) ? s_dup((char *)&args.intmax) : p->out;
	p->out = chk(O) ? c_itoa_base(args.intmax, 8) : p->out;
	p->out = chk(X | P) ? c_itoa_base(args.intmax, 16) : p->out;
	p->out = chk(S) && args.ptr ? s_dup((char *)args.ptr) : p->out;
	p->out = chk(S) && !args.ptr ? s_dup("(null)") : p->out;
	p->out = chk(ESC) ? s_dup("%") : p->out;
}

static void			pf_padding(t_printf *p, char *pre)
{
	pre = chk(F | E | I | D) && g_s == -1 ? s_dup("-") : pre;
	pre = chk(PLUS) && chk(F | E | I | D) && g_s >= 0 ? s_dup("+") : pre;
	pre = chk(SPACE) && chk(F | D) ? s_dup(" ") : pre;
	pre = asr(HASH | X) && g_s ? s_dup("0x") : pre;
	pre = chk(P) ? s_dup("0x") : pre;
	pre = asr(HASH | B) ? s_dup("0b") : pre;
	pre = asr(HASH | O) && g_p < (int)s_len(p->out) + 1 ? s_dup("0") : pre;
	g_p += s_len(pre);
	p->out = s_join_free(pre, p->out, 3);
	p->out = chk(S | C | ESC) ? p->out : s_fill(p->out, g_p, "0");
	p->out = chk(S | C | ESC) && g_p ? s_cut(p->out, g_p) : p->out;
	pf_move_prefix(p->out);
	if (asr(LEFT | ZERO) && !chk(S | C | ESC | DOT))
		p->out = s_fill(p->out, g_w, "0-");
	else if (chk(ZERO) && (chk(F | E) || !chk(DOT)))
		p->out = s_fill(p->out, g_w, "0");
	else if (chk(LEFT))
		p->out = s_fill(p->out, g_w, "-");
	else
		p->out = s_fill(p->out, g_w, "");
	pf_move_prefix(p->out);
	if (is_upper(p->type))
		s_iter(&p->out, c_toupper);
}

static t_stack		*pf_core_loop(t_printf *p, t_stack *stack)
{
	char			*tmp;
	char 			*pos;
	size_t			i;

	tmp = s_cdup(p->in, '%');
	if (!(pos = s_chr(p->in, '%')))
		st_push(&stack, tmp);
	else
	{
		st_push(&stack, tmp);
		i = find("%CDEOSUXbcdefiopsux", ++pos);
		p->arg_str = s_ndup(pos, i);
		p->type = p->arg_str[i - 1];
		pf_set_flags(p->arg_str, c_tolower(p->type));
		pf_set_size();
		pf_delist(p);
		pf_convert(p, 0);
		pf_padding(p, NULL);
		st_push(&stack, p->out);
		p->in = pos + s_len(p->arg_str);
		s_del(&p->arg_str);
		return (pf_core_loop(p, stack));
	}
	return (stack);
}

int					ft_vasprintf(char **out, const char *format, va_list ap)
{
	t_printf		*p;
	char			*tmp;
	t_stack			*stack;

	p = (t_printf *)v_alloc(sizeof(t_printf));
	p->in = s_dup(format);
	tmp = p->in;
	va_copy(p->arg, ap);
	stack = pf_core_loop(p, NULL);
	s_del(&tmp);
	while ((tmp = (char *)st_pop(&stack)))
		*out = s_join_free(tmp, *out, 3);
	free(stack);
	s_del(&tmp);
	va_end(p->arg);
	free(p);
	return (s_len(*out));
}
