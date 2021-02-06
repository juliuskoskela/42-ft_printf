/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldcol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:22:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:23:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

uint64_t			b_fldcol(uint64_t *field, uint64_t col, uint64_t size)
{
	uint64_t		d;
	uint64_t		i;

	i = 0;
	d = 0;
	while (i < size - 1)
	{
		if (b_checknth(field[i], col) == 1)
			d |= 1 << i;
		i++;
	}
	return (d);
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldcol
**
**	Get column `col` from the bit-field `field` from the area denoted by `size`.
**
**  ----------------------------------------------------------------------------
*/
