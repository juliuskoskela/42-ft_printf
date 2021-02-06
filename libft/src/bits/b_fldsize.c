/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:24:28 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:36:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	b_fldsize(t_field *field)
{
	uint64_t		x;
	uint64_t		y;
	uint64_t		i;
	uint64_t		nb;

	i = 0;
	y = 0;
	x = 0;
	if (!field)
		return ;
	while (i < field->h)
	{
		if (field->row[i] != 0)
		{
			y++;
			nb = m_log(field->row[i]) + 1;
			if (nb > x)
				x = nb;
		}
		i++;
	}
	field->h = y;
	field->w = x;
	field->bh = y;
	field->bw = x;
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldsize
**
**	Calculate new size of `field`.
**
**  ----------------------------------------------------------------------------
*/
