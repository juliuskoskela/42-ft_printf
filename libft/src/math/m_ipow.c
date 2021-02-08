/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_ipow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:34:10 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 00:34:53 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int64_t				m_ipow(int64_t base, int64_t exp)
{
	int64_t			tmp;
	int64_t			i;

	i = 0;
	tmp = base;
	if (base == 0 && exp == 0)
		return (1);
	else if (base == 0)
		return (0);
	else if (exp == 0)
		return (1);
	while (i < exp - 1)
	{
		tmp *= base;
		i++;
	}
	return (tmp);
}

/*
**  ----------------------------------------------------------------------------
**
**	M_ipow
**
**	Calculate (integer) `base` raised to the (integer) `exp`th power.
**
**  ----------------------------------------------------------------------------
*/
