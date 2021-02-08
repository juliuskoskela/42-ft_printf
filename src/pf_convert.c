/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:31:10 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:43:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
