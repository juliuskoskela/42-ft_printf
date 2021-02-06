/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 03:47:58 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/23 13:34:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char				*s_copy(char *str, size_t start, size_t end, size_t flag)
{
	char			*out;
	size_t			i;

	if (!str || start > end)
		return (NULL);
	out = NULL;
	out = end > 0 ? s_new(end - start) : s_new(s_len(str));
	i = 0;
	while (i < end - start && str[i + start])
	{
		out[i] = str[i + start];
		i++;
	}
	if (flag == 1)
		s_del(&str);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_copy
**
**	A string copy with specified start and end points for copied area and a
**	flag to free the input string if necessary. If end is set to 0, the whole
**	string will be copied. Result string is allocated.
**
**  ----------------------------------------------------------------------------
*/
