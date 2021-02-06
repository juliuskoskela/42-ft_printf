/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_cpy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		*v_cpy(void *dest, const void *src, uint64_t n)
{
	const char	*s;
	char		*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = (const char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*
**  ----------------------------------------------------------------------------
**
**	V_ccpy
**
**	Void memory copy; copies `n` bytes from memory area `src` to memory area
**	`dst`. If `dst` and `src` overlap, behavior is undefined. Applications in
**	which `dst` and `src` might overlap should use `v_move` instead.
**
**  ----------------------------------------------------------------------------
*/
