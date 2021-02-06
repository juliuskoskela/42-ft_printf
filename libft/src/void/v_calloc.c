/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_calloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:08 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void			*v_calloc(uint64_t nmemb, uint64_t size)
{
	unsigned	nbytes;
	void		*addr;

	nbytes = nmemb * size;
	addr = malloc(nbytes);
	if (addr)
		v_set(addr, 0, nbytes);
	return (addr);
}

/*
**  ----------------------------------------------------------------------------
**
**	V_calloc
**
**	Void memory allocation (c); allocates and formats `nmemb` amount of
**	elements of size `size`.
**
**  ----------------------------------------------------------------------------
*/
