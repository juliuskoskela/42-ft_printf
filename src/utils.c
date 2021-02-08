/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:21:05 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 03:14:27 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t			chk(size_t flags, size_t fl)
{
	return (flags & fl ? flags & fl : 0);
}

size_t			set(size_t flags, size_t fl)
{
	return (flags |= fl);
}

size_t			asr(size_t fl)
{
	return ((fl & g_flags) == fl ? fl : 0);
}
