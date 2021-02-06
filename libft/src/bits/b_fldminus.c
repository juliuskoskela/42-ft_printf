/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldminus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:23:26 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:28:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		b_fldminus(t_field *board, t_field *field)
{
	uint64_t	i;

	i = 0;
	if (!field || !board)
		return ;
	while (i < field->h)
	{
		board->row[i] = board->row[i] - field->row[i];
		i++;
	}
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldminus
**
**	Substract `field` rows from the rows in `board.
**
**  ----------------------------------------------------------------------------
*/
