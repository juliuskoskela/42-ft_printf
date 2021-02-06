/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_flddel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:22:28 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:23:39 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		b_flddel(t_field *field)
{
	if (field)
	{
		if (field->row)
			free(field->row);
		free(field);
	}
}

/*
**  ----------------------------------------------------------------------------
**
**	B_flddel
**
**	Delete field.
**
**  ----------------------------------------------------------------------------
*/
