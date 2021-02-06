/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_atof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:24:52 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static double	c_atof_sub(const char *str, double res)
{
	int			decimal;

	decimal = 0;
	while (is_digit(*str) == 1 && *str != '.')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	str++;
	if (*str == '\0')
		return (res);
	while (is_digit(*str) == 1)
	{
		res = res * 10 + (*str - 48);
		str++;
		decimal++;
	}
	while (decimal--)
		res = res / 10;
	return (res);
}

double			c_atof(const char *str)
{
	double		res;
	double		negative;

	negative = 1;
	res = 0;
	while (is_wspace(*str) == 1)
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	res = c_atof_sub(str, res);
	return (res * negative);
}

/*
**  ----------------------------------------------------------------------------
**
**	C_atof
**
**	Convert a string of characters into a float.
**
**  ----------------------------------------------------------------------------
*/
