/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_roundl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:35:26 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:40:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/libft.h"

long double			m_roundl(long double x)
{
	long double		toint;
	t_ldbits		u;
	int				e;
	long double		y;

	u.ldbl = x;
	e = u.u80.u16 & 0x7fff;
	toint = 1 / LDBL_EPSILON;
	if (e >= 0x3fff + LDBL_MANT_DIG - 1)
		return (x);
	if (u.u80.u16 >> 15)
		x = -x;
	if (e < 0x3fff - 1)
		return (0 * u.ldbl);
	y = x + toint - toint - x;
	if (y > 0.5)
		y = y + x - 1;
	else if (y <= -0.5)
		y = y + x + 1;
	else
		y = y + x;
	if (u.u80.u16 >> 15)
		y = -y;
	return (y);
}
