/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_transpose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:20:20 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/20 19:34:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_transpose(t_mtx4 src)
{
	t_mtx4		out;

	out.name = s_join(src.name, "^");
	out.v1.x = src.v1.x;
	out.v1.y = src.v2.x;
	out.v1.z = src.v3.x;
	out.v1.w = src.v4.x;
	out.v2.x = src.v1.y;
	out.v2.y = src.v2.y;
	out.v2.z = src.v3.y;
	out.v2.w = src.v4.y;
	out.v3.x = src.v1.z;
	out.v3.y = src.v2.z;
	out.v3.z = src.v3.z;
	out.v3.w = src.v4.z;
	out.v4.x = src.v1.w;
	out.v4.y = src.v2.w;
	out.v4.z = src.v3.w;
	out.v4.w = src.v4.w;
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	G_transpose
**
**	Transpose t_mtx4 `src`.
**
**  ----------------------------------------------------------------------------
*/
