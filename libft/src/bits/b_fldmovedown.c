/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldmovedown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:23:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:28:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void		b_fldmovedown_1(t_field *field)
{
	uint64_t		i;

	i = field->h - 1;
	while (i > 0)
	{
		field->row[i] = field->row[i - 1];
		field->row[i - 1] = 0;
		i--;
	}
}

void			b_fldmovedown(t_field *field, uint64_t steps)
{
	uint64_t		i;

	i = steps;
	if (!field || !field->row)
		return ;
	while (steps)
	{
		b_fldmovedown_1(field);
		steps--;
	}
	field->y += i;
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldmovedown
**
**	Move field down in its container by 1 step.
**
**  ----------------------------------------------------------------------------
*/
