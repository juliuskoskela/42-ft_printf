/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:53 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		*v_move(void *dest, const void *src, uint64_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		v_cpy(dest, src, n);
	else
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return (dest);
}

/*
**  ----------------------------------------------------------------------------
**
**	V_move
**
**	Void memory move; copies `len` bytes from string `src` to string `dst`.
**	The two strings may overlap; the copy is always done in a non-destructive
**	manner.
**
**  ----------------------------------------------------------------------------
*/
