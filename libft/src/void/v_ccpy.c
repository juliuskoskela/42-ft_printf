/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ccpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:12 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		*v_ccpy(void *dst, const void *src, int c, uint64_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n != 0)
	{
		*dest2 = *src2;
		if (*src2 == (unsigned char)c)
			return (dest2 + 1);
		dest2++;
		src2++;
		n--;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	V_ccpy
**
**	Void memory copy (c); copies bytes from string src to string dst.  If
**	the character c (as converted to an unsigned char) occurs in the string
**	src, the copy stops and a pointer to the byte after the copy of c in the
**	string dst is returned.  Otherwise, n bytes are copied, and a NULL
**	pointer is returned.
**
**  ----------------------------------------------------------------------------
*/
