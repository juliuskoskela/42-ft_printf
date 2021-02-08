/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_move_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:29:18 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:29:26 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	Move prefix when zero padding a prefixed number with zeros.
*/

static int			pf_move_prefix(t_printf *p, char *s)
{
	size_t		i;
	size_t		r;

	i = 0;
	r = 0;
	while (!(s_chr(" +-xb", s[i])) && s[i])
		i++;
	if (p->sign == -1 && s[i] == '-' && s[0] == '0' && f_c(p->f, SIGNED))
		s_swp(&s[i], &s[0]);
	else if (p->sign == 1 && s[i] == '+' && s[0] == '0' && f_c(p->f, PLUS))
		s_swp(&s[i], &s[0]);
	else if ((f_a(p->f, HASH | X) || f_c(p->f, P)) && s[i] == 'x' \
	&& s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (f_a(p->f, HASH | B) && s[i] == 'b' && s[0] == '0')
		s_swp(&s[i], &s[1]);
	else if (f_a(p->f, SPACE) && s[i] == ' ' && s[0] == '0')
		s_swp(&s[i], &s[0]);
	return (r);
}
