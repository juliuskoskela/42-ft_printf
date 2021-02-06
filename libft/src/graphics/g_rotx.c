/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rotx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:34:16 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/20 19:34:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_rotx(double angle)
{
	t_mtx4		out;

	out.name = s_dup("X");
	out.v1 = g_vct4(1.0, 0.0, 0.0, 0.0);
	out.v2 = g_vct4(0.0, cos(m_rad(angle)), -sin(m_rad(angle)), 0.0);
	out.v3 = g_vct4(0.0, sin(m_rad(angle)), cos(m_rad(angle)), 0.0);
	out.v4 = g_vct4(0.0, 0.0, 0.0, 1.0);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	G_rotx
**
**	Create a rotation matrix of `angle` degrees in the x direction.
**
**  ----------------------------------------------------------------------------
*/
