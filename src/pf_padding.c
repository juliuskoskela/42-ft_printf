/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:31:51 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:37:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			pf_move_prefix(t_printf *p, char *s)
{
	size_t		i;
	size_t		r;

	i = 0;
	r = 0;
	while (!(s_chr(" +-xb", s[i])) && s[i])
		i++;
	if (p->sign == -1 && s[i] == '-' && s[0] == '0' && f_c(p->f, SIGNED))
		s_swp(&s[i], &s[0]);
	else if (p->sign == 1 && s[i] == '+' && s[0] == '0' && f_c(p->f, PLUS))
		s_swp(&s[i], &s[0]);
	else if ((f_a(p->f, HASH | X) || f_c(p->f, P)) && s[i] == 'x' \
	&& s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (f_a(p->f, HASH | B) && s[i] == 'b' && s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (f_a(p->f, SPACE) && s[i] == ' ' && s[0] == '0')
		s_swp(&s[i], &s[0]);
}

static void			pf_get_prefix(t_printf *p, char *pre)
{
	pre = f_c(p->f, F | E | I | D) && p->sign == -1 ? s_dup("-") : pre;
	pre = f_c(p->f, PLUS) && f_c(p->f, F | E | I | D) \
	&& p->sign >= 0 ? s_dup("+") : pre;
	pre = f_c(p->f, SPACE) && f_c(p->f, F | D) && !f_c(p->f, PLUS) \
	&& p->sign != -1 ? s_dup(" ") : pre;
	pre = f_a(p->f, HASH | X) && p->sign ? s_dup("0x") : pre;
	pre = f_c(p->f, P) ? s_dup("0x") : pre;
	pre = f_a(p->f, HASH | B) ? s_dup("0b") : pre;
	pre = f_a(p->f, HASH | O) && p->p < (int)s_len(p->out) + 1 \
	? s_dup("0") : pre;
	p->p += s_len(pre);
	p->out = s_join_free(pre, p->out, 3);
}

void				pf_padding(t_printf *p)
{
	pf_get_prefix(p, NULL);
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
