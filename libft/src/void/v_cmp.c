/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_cmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:25 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int			v_cmp(const void *s1, const void *s2, uint64_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}

/*
**  ----------------------------------------------------------------------------
**
**	V_chr
**
**	Void memory compare; compares byte string `s1` against byte string `s2`.
**	Both strings are assumed to be n bytes long.
**
**	The `v_chr` function returns zero if the two strings are identical, oth-
**	erwise returns the difference between the first two differing bytes
**	(treated as unsigned char values, so that `\200' is greater than `\0',
**	for example). Zero-length strings are always identical.
**
**  ----------------------------------------------------------------------------
*/
