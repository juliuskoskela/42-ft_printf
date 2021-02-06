/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:24:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:31:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		b_fldplus(t_field *board, t_field *field)
{
	uint64_t	i;

	i = 0;
	if (!field || !board)
		return ;
	while (i < field->h)
	{
		board->row[i] = board->row[i] + field->row[i];
		i++;
	}
	board->bh = field->bh;
	board->bw = field->bw;
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldplus
**
**	Add `field` rows from the rows in `board.
**
**  ----------------------------------------------------------------------------
*/
