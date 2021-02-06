/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rotz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:36:32 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/20 19:36:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_mtx4			g_rotz(double angle)
{
	t_mtx4		out;

	out.name = s_dup("Z");
	out.v1 = g_vct4(cos(m_rad(angle)), -sin(m_rad(angle)), 0.0, 0.0);
	out.v2 = g_vct4(sin(m_rad(angle)), cos(m_rad(angle)), 0.0, 0.0);
	out.v3 = g_vct4(0.0, 0.0, 1.0, 0.0);
	out.v4 = g_vct4(0.0, 0.0, 0.0, 1.0);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	G_rotz
**
**	Create a rotation matrix of `angle` degrees in the z direction.
**
**  ----------------------------------------------------------------------------
*/
