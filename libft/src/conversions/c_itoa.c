/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:25:17 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/26 22:56:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int		al_nbdigit(int64_t n)
{
	int			res;
	uint64_t	tmp;

	res = 1;
	tmp = (n < 0 ? -n : n);
	while (tmp >= 10)
	{
		res++;
		tmp /= 10;
	}
	return (res);
}

char			*c_itoa(int64_t n)
{
	char		*res;
	int64_t		i;
	int64_t		len;

	len = (n < 0 ? al_nbdigit(n) + 1 : al_nbdigit(n));
	if (!(res = s_new(len)))
		return (NULL);
	res[0] = (n == 0 ? '0' : '-');
	if ((unsigned long)n == -9223372036854775808U)
	{
		s_del(&res);
		return (s_dup("9223372036854775808"));
	}
	i = len - 1;
	if (n < 0)
		n = -n;
	while (n)
	{
		res[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (res);
}

/*
**  ----------------------------------------------------------------------------
**
**	C_itoa
**
**	Convert an int into a string.
**
**	Add for compatibility:
**
**	if (n == -2147483648)
**		return (s_cpy(str, "-2147483648"));
**
**  ----------------------------------------------------------------------------
*/
