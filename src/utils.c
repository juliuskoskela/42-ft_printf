/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:21:05 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/05 13:24:24 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		chr(char *arg_str, char *fl)
{
	return (s_str(arg_str, fl) ? 1 : 0);
}

int			chk(size_t fl)
{
	return (g_flag & fl ? fl : 0);
}

size_t		set(size_t fl)
{
	return (g_flag |= fl);
}

int			asr(size_t fl)
{
	return ((fl & g_flag) == fl ? fl : 0);
}

int			swp(char *a, char *b)
{
	char			c;

	c = *a;
	*a = *b;
	*b = c;
	return (c);
}

int			find(char *dst, char *str)
{
	size_t			i;
	char			*tmp;

	i = 1;
	tmp = NULL;
	while (!(s_chr(dst, str[i - 1])))
		i++;
	if (s_chr(dst, str[i - 1]))
		return (i);
	else
		return (0);
}

char		*is_abnormal(double nbr)
{
	if (nbr != nbr)
		return (s_dup("nan"));
	if (nbr == POS_INF)
		return (s_dup("inf"));
	if (nbr == NEG_INF)
		return (s_dup("-inf"));
	return (NULL);
}
