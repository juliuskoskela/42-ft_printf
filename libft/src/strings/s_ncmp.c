/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ncmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:46 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int			s_ncmp(const char *s1, const char *s2, uint64_t n)
{
	uint64_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_ncmp
**
**	String compare (n); lexicographically compares `n` characters in the
**	null-terminated strings `s1` and `s2`.
**
**	Returns 0 if strings are identical. Otherwise it returns the difference
**	(in integers) between the first non-matching characters in the strings.
**
**  ----------------------------------------------------------------------------
*/
