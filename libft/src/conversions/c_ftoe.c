/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ftoe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 08:16:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/01 10:51:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char		*check_naninf(double nbr)
{
	if (nbr != nbr)
		return (s_dup("nan"));
	if (nbr == POS_INF)
		return (s_dup("inf"));
	if (nbr == NEG_INF)
		return (s_dup("-inf"));
	return (NULL);
}

char			*c_ftoe(long double nbr, size_t p)
{
	char		*out;
	char		*tmp;
	long double	sign;
	int			i;

	i = 0;
	sign = 1;
	if ((tmp = check_naninf(nbr)))
		return (tmp);
	if (nbr < 0)
		sign = -1;
	nbr = m_fabs(nbr);
	while (nbr >= 10.0)
	{
		nbr /= 10.0;
		i++;
	}
	nbr = nbr * sign;
	tmp = c_ftoa(nbr, p);
	out = s_join_free(tmp, "e+0", 1);
	tmp = s_join_free(out, c_itoa_base(i, 10), 2);
	free(out);
	return (tmp);
}

/*
**  ----------------------------------------------------------------------------
**
**	C_ftoe
**
**	Convert long double `nbr` into scientific notation in ascii.
**
**  ----------------------------------------------------------------------------
*/
