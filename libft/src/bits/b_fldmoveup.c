/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldmoveup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:23:54 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:29:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void		b_fldmoveup_1(t_field *field)
{
	uint64_t		i;

	i = 0;
	if (!field)
		return ;
	while (i < field->h - 1)
	{
		field->row[i] = field->row[i + 1];
		field->row[i + 1] = 0;
		i++;
	}
}

void			b_fldmoveup(t_field *field, uint64_t steps)
{
	while (steps)
	{
		b_fldmoveup_1(field);
		steps--;
	}
	field->y -= steps;
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldmoveup
**
**	Move field up in its container by 1 step.
**
**  ----------------------------------------------------------------------------
*/
