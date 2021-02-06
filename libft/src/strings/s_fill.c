/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:20:36 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/03 21:24:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char			*s_fill(char *data, size_t b_size, char *flags)
{
	char		*out;
	size_t		i;
	size_t		j;
	size_t		d_size;

	d_size = s_len(data);
	j = 0;
	if (b_size < d_size)
		return (data);
	i = s_chr(flags, '-') ? 0 : b_size - d_size;
	out = s_chr(flags, '0') ? s_newc(b_size, '0') : s_newc(b_size, ' ');
	while (data[j])
		out[i++] = data[j++];
	s_del(&data);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_fill
**
**	Create a new string of `b_size` and fill it with the string `data`.
**	'0' = format with zeros instead of space.
**	'-' = left adjust
**
**  ----------------------------------------------------------------------------
*/
