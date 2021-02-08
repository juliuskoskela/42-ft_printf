/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_delist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:30:33 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:30:41 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
