/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_primefac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 04:03:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void		dl_putint(t_dlist **list, uint64_t n)
{
	uint64_t	*nb;

	nb = (uint64_t *)malloc(sizeof(uint64_t));
	*nb = n;
	dl_putlast(list, nb);
}

t_dlist			*m_primefac(uint64_t n)
{
	t_dlist		*out;
	uint64_t	i;

	while (n % 2 == 0)
	{
		dl_putint(&out, 2);
		n = n / 2;
	}
	i = 3;
	while (i <= m_sqrt(n))
	{
		while (n % i == 0)
		{
			dl_putint(&out, i);
			n = n / i;
		}
		i = i + 2;
	}
	if (n > 2)
	{
		dl_putint(&out, n);
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	M_primefac
**
**	Calculates the prime factorials of `n` and returns a linked list with
**	the results.
**
**  ----------------------------------------------------------------------------
*/
