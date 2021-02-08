/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_treat_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:40:40 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 04:31:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char			*c_decimal(long double nbr, int prec, size_t flags)
{
	char			*out;

	if (prec > 15)
		out = c_ftoa(nbr, 15);
	else
		out = c_ftoa(nbr, prec);
	if (f_a(flags, DOT | HASH) && prec == 0)
		out[s_lenc(out, '.') + 1] = '\0';
	else if (f_c(flags, DOT) && prec == 0)
		out[s_lenc(out, '.')] = '\0';
	return (out);
}

char				*pf_treat_float(long double nbr, int prec, size_t flags)
{
	char			*out;
	long double		sign;
	int				i;

	i = 0;
	sign = 1;
	if (!f_c(flags, E) || is_abnormal(nbr))
		return (c_decimal(nbr, prec, flags));
	sign = nbr < 0 ? -1 : 1;
	nbr = m_fabs(nbr);
	while (nbr >= 10.0)
	{
		nbr /= 10.0;
		i++;
	}
	nbr = nbr * sign;
	out = c_decimal(nbr, prec, flags);
	out = s_join_free(s_join_free(out, "e+0", 1), c_itoa_base(i, 10), 3);
	return (out);
}
