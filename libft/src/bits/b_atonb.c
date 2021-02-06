/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_atonb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:42:11 by esukava           #+#    #+#             */
/*   Updated: 2021/01/03 01:19:24 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

uint64_t		b_atonb(char *str, char c, uint64_t size)
{
	uint64_t	i;
	uint64_t	nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		if (str[i] == c)
			nb |= 1 << i;
		if (str[i] != '\n')
			i++;
	}
	return (nb);
}

/*
**  ----------------------------------------------------------------------------
**
**	B_atonb
**
**	Convert a string into bits. Characters of value `c` are considered 1
**	and all other values are considered 0.
**
**  ----------------------------------------------------------------------------
*/
