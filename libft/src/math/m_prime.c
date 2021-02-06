/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_prime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 03:52:37 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

uint64_t		m_prime(uint64_t n)
{
	uint64_t	i;

	i = 5;
	if (n <= 3)
		return (1);
	else if (n % 2 == 0 || n % 3 == 0)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
		i = i + 6;
	}
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	M_prime
**
**	Calculate if `n` is a prime number and return 1 if so.
**
**  ----------------------------------------------------------------------------
*/
