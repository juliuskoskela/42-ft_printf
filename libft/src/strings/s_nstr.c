/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:15 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char		*s_nstr(const char *h, const char *n, uint64_t len)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	if (!s_len(n))
		return ((char *)h);
	while (i < len && h[i] != '\0')
	{
		j = 0;
		while (i + j < len && h[i + j] == n[j] && n[j] != '\0')
			j++;
		if (n[j] == '\0')
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_nstr
**
**	Locate substring (n); function locates the first occurrence of the
**	null-terminated string `n` in the string `h`, where not more than len
**	characters are searched.  Characters that appear after a `\0' character
**	are not searched.
**
**  ----------------------------------------------------------------------------
*/
