/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:24:20 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/06 18:23:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void		b_fldprint1(uint64_t *field, uint64_t w, uint64_t h)
{
	uint64_t		i;

	i = 0;
	while (i < h)
	{
		p_bits(field[i], w);
		if (!(write(1, "\n", 1)))
			return ;
		i++;
	}
}

void			b_fldprint(t_field *field)
{
	if (!field)
		return ;
	b_fldprint1(field->row, field->w, field->h);
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldprint
**
**	Print field.
**
**  ----------------------------------------------------------------------------
*/
