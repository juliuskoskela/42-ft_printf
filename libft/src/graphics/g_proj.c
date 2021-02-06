/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_proj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:35:18 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/20 19:35:19 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_proj(double fv, double rt, int n, int f)
{
	t_mtx4		out;

	out.name = s_dup("P");
	out.v2 = g_vct4(0.0, 1 / tan(0.5 * m_rad(fv)), 0.0, 0.0);
	out.v1 = g_vct4(out.v2.y / rt, 0.0, 0.0, 0.0);
	out.v3 = g_vct4(0.0, 0.0, -1 * (-n - f) / (n - f), (2 * n * f) / (n - f));
	out.v4 = g_vct4(0.0, 0.0, -1.0, 0.0);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	G_proj
**
**	3D to 2D projection matrix.
**	`fv` = field of view in degrees
**	`rt` = ratio (for example 16 / 9)
**	`n` = nearest pixel to the camera to be rendered
**	`f` = furthest pixel to the camera to be rendered
**
**  ----------------------------------------------------------------------------
*/
