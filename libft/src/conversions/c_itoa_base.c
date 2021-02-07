/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:03:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/07 00:33:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char			*c_itoa_base(int64_t nb, int64_t base)
{
	size_t		i;
	size_t		sign;
	char		*out;
	char		*tab;

	i = 0;
	sign = nb < 0 ? -1 : 1;
	nb = nb * sign;
	tab = "0123456789abcdef";
	if (base > 16 || base < 1)
		return (NULL);
	else if (base == 10)
		return (c_itoa(nb));
	else if (base == 2)
		return (c_bitoa(nb, 64));
	out = s_new(m_dcnt(nb, base) + 1);
	while (nb > base)
	{
		out[i] = tab[nb % base];
		nb = nb / base;
		i++;
	}
	out[i] = tab[nb % base];
	out = sign == 1 ? s_rev(out) : s_join_free("-", s_rev(out), 2);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	C_itoa_base
**
**	Convert `nb` base 10 converted to a string of characters in base `base`.
**
**  ----------------------------------------------------------------------------
*/
