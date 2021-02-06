/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:37 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char		*s_str(const char *h, const char *n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (h[0] == '\0' && n[0] == '\0')
		return ((char *)h);
	while (h[i] != '\0')
	{
		j = 0;
		while (n[j] != '\0' && h[i + j] == n[j])
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
**	S_str
**
**	Locate substring; locates the first occurrence of the
**	null-terminated string `n` in the string `h`. Characters that appear
**	after a `\0' character are not searched.
**
**  ----------------------------------------------------------------------------
*/
