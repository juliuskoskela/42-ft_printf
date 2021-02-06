/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldmoveleft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:23:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:28:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		b_fldmoveleft(t_field *field, uint64_t steps)
{
	uint64_t		i;

	i = 0;
	if (!field || !field->row)
		return ;
	while (i < field->h)
	{
		field->row[i] = field->row[i] >> steps;
		i++;
	}
	field->x -= steps;
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldmoveleft
**
**	Move field left in its container by 1 step.
**
**  ----------------------------------------------------------------------------
*/
