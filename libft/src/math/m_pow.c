/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 01:58:34 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/06 03:22:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "math.h"

static double	m_pow__(double base, double exp, double high, double low)
{
	double		sqr;
	double		acc;
	double		mid;

	sqr = m_sqrt(base);
	acc = sqr;
	mid = high / 2;
	while (m_fabs(mid - exp) > POWPREC)
	{
		sqr = m_sqrt(sqr);
		if (mid <= exp)
		{
			low = mid;
			acc *= sqr;
		}
		else
		{
			high = mid;
			acc *= (1 / sqr);
		}
		mid = (low + high) / 2;
	}
	return (acc);
}

static double	m_pow_(double base, double exp, double high, double low)
{
	double		temp;

	if (exp >= 1)
	{
		temp = m_pow_(base, exp / 2, high, low);
		return (temp * temp);
	}
	else
		return (m_pow__(base, exp, high, low));
}

double			m_pow(double base, double exp)
{
	double		high;
	double		low;

	low = 0.0;
	high = 1.0;
	return (m_pow_(base, exp, high, low));
}

/*
**  ----------------------------------------------------------------------------
**
**	M_pow
**
**	Calculate `base` raised to the `exp`th power.
**
**  ----------------------------------------------------------------------------
*/
