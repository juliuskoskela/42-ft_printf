/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldoverlap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:24:06 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:30:49 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int			b_fldoverlap(t_field *board, t_field *field)
{
	uint64_t		i;

	i = 0;
	if (!board || !field)
		return (-1);
	while (i <= board->h)
	{
		if ((board->row[i] & field->row[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldoverlap
**
**	If fields overlap at any position inside the container of `board` return 0.
**	Otherwise return 1.
**
**  ----------------------------------------------------------------------------
*/
