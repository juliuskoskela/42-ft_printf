/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:04 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int			s_nequ(char const *s1, char const *s2, uint64_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (!s_ncmp(s1, s2, n))
		return (0);
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_nequ
**
**	String equal (n); compares `n` characters from strings `s1` and `s2`
**	and returns 1 if the strings are equal.
**
**  ----------------------------------------------------------------------------
*/
