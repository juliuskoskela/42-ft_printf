/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mult_mtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:28:34 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/20 19:01:26 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_mult_mtx(t_mtx4 a, t_mtx4 b)
{
	t_mtx4		out;

	out.name = s_join(a.name, b.name);
	out.v1.x = g_dot(a.v1, b.v1);
	out.v2.x = g_dot(a.v1, b.v2);
	out.v3.x = g_dot(a.v1, b.v3);
	out.v4.x = g_dot(a.v1, b.v4);
	out.v1.y = g_dot(a.v2, b.v1);
	out.v2.y = g_dot(a.v2, b.v2);
	out.v3.y = g_dot(a.v2, b.v3);
	out.v4.y = g_dot(a.v2, b.v4);
	out.v1.z = g_dot(a.v3, b.v1);
	out.v2.z = g_dot(a.v3, b.v2);
	out.v3.z = g_dot(a.v3, b.v3);
	out.v4.z = g_dot(a.v3, b.v4);
	out.v1.w = g_dot(a.v4, b.v1);
	out.v2.w = g_dot(a.v4, b.v2);
	out.v3.w = g_dot(a.v4, b.v3);
	out.v4.w = g_dot(a.v4, b.v4);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	G_mult_mtx
**
**	Multiply matrix `a` by matrix `b`.
**
**  ----------------------------------------------------------------------------
*/
