/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:44:07 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/06 01:20:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_printf(const char *restrict fmt, ...)
{
	int				ret;
	char			*out;
	va_list			ap;

	out = NULL;
	va_start(ap, fmt);
	ret = ft_vasprintf(&out, fmt, ap);
	if (ret == -1)
	{
		p_str("\nft_printf error: format not set!\n");
		return (-1);
	}
	else if (!out)
	{
		p_str("\nft_printf error: failed!\n");
		return (-1);
	}
	write(1, out, s_len(out));
	s_del(&out);
	va_end(ap);
	return (ret);
}
