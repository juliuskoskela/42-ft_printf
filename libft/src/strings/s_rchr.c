/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:21 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char		*s_rchr(const char *s, int c)
{
	int		i;

	i = s_len(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_chr
**
**	The `s_chr` function locates the last occurrence of `c` (converted to a
**	char) in the string pointed to by `s`. The terminating null character is
**	considered to be part of the string; therefore if `c` is `\0`, the
**	function locates the terminating `\0`.
**
**  ----------------------------------------------------------------------------
*/
