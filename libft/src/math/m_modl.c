/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_modl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:50:28 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/26 21:53:06 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long double		m_modl(long double x, long double *iptr)
{
	t_modl		vars;

	vars.u = (t_ldshape)x;
	vars.e = (vars.u.se & 0x7fff) - 0x3fff;
	vars.s = vars.u.se >> 15;
	if (vars.e >= LDBL_MANT_DIG - 1)
	{
		*iptr = x;
		return (vars.s ? -0.0 : 0.0);
	}
	if (vars.e < 0)
	{
		*iptr = vars.s ? -0.0 : 0.0;
		return (x);
	}
	return (-vars.y);
}

/*
**  ----------------------------------------------------------------------------
**
**	M_modl *UNSTESTED*
**
**	Convert long double `x` into a decimal representation. Function returns
**	mantissa and integral part is stored in the previously allocated int
**	pointer `iptr`.
**
**  ----------------------------------------------------------------------------
*/
