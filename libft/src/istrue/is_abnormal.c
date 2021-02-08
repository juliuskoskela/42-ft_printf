/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_abnormal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:59:02 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 02:00:27 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int				is_abnormal(double nbr)
{
	if (nbr != nbr)
		return (1);
	if (nbr == POS_INF)
		return (2);
	if (nbr == NEG_INF)
		return (3);
	return (0);
}

/*
**  ----------------------------------------------------------------------------
**
**	Is_abnormal
**
**	Returns 0 if `nbr` isn't abnormal, 1 if it's not a number, 2 if it's
**	positive infinity and 3 if negative infinity.
**
**  ----------------------------------------------------------------------------
*/
