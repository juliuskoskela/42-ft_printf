/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:41 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char			*s_sub(char const *s, unsigned int start, uint64_t len)
{
	char		*out;
	uint64_t	i;

	i = 0;
	if (!s)
		return (NULL);
	out = (char *)malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_sub
**
**	Substring duplicate; Duplicate contents of `s` starting from index `start`
**	for lenght `len`.
**
**	Return a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
