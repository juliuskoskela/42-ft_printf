/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:29:49 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:30:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
