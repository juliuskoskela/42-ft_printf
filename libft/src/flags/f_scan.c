/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_scan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 02:44:58 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:40:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t				f_scan(char *flag_order, char *flags_str)
{
	size_t			i;
	size_t			j;
	size_t			ret;
	size_t			flags;

	i = 0;
	j = 0;
	flags = 0;
	while (flags_str[i])
	{
		if (s_chr(flag_order, c_tolower(flags_str[i])))
		{
			while (flag_order[j] != c_tolower(flags_str[i]))
				j++;
			ret = (size_t)m_ipow(2, j);
			flags |= ret;
			j = 0;
		}
		i++;
	}
	return (flags);
}

/*
**  ----------------------------------------------------------------------------
**
**	F_scan
**
**	F_scan takes as parameter a `flag_order` string which represents the
**	symbols used in the flags in their order of bit index. For example a order
**	of "adg" translates to [0] = a, [1] = d, [2] = g. It then toggles on the
**	corresponding bits in `flags`. To note: One `flags` variable has room for
**	64 flags.
**
**  ----------------------------------------------------------------------------
*/
