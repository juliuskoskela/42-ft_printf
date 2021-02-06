/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mapi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:34 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char		*s_mapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*d;

	n = 0;
	d = (char *)malloc(sizeof(char) * (s_len(s)) + 1);
	if (d == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		d[n] = f(n, s[n]);
		n++;
	}
	d[n] = '\0';
	return (d);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_mapi
**
**	String map; applies function `f` on all elements of string `out` and stores
**	the results in string `out`. Unlike s_iter it passes the index as
**	parameter to function `f`.
**
**	Returns a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
