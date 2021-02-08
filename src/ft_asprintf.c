/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:44:07 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 20:58:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_asprintf(char **out, const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = ft_vasprintf(out, format, ap);
	if (ret == -1)
	{
		p_str("\nft_printf error: format not set!\n");
		return (-1);
	}
	else if (*out == NULL)
	{
		p_str("\nft_printf error: failed!\n");
		return (-1);
	}
	va_end(ap);
	return (ret);
}
