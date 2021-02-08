/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:50:47 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/08 21:37:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_stack		*pf_core_loop(t_printf *p, t_stack *stack)
{
	char			*tmp;
	char			*pos;
	size_t			i;

	tmp = s_cdup(p->in, '%');
	if (!(pos = s_chr(p->in, '%')))
		st_push(&stack, tmp);
	else
	{
		st_push(&stack, tmp);
		i = s_find_first("%CDEOSUXbcdefiopsux", ++pos);
		p->flags = s_ndup(pos, i);
		p->type = p->flags[i - 1];
		pf_set_flags(p);
		pf_delist(p);
		pf_convert(p, 0);
		pf_padding(p);
		st_push(&stack, p->out);
		p->in = pos + s_len(p->flags);
		s_del(&p->flags);
		return (pf_core_loop(p, stack));
	}
	return (stack);
}

int					ft_vasprintf(char **out, const char *format, va_list ap)
{
	t_printf		*p;
	char			*tmp;
	t_stack			*stack;

	p = (t_printf *)v_alloc(sizeof(t_printf));
	p->in = s_dup(format);
	tmp = p->in;
	va_copy(p->ap, ap);
	stack = pf_core_loop(p, NULL);
	s_del(&tmp);
	while ((tmp = (char *)st_pop(&stack)))
		*out = s_join_free(tmp, *out, 3);
	free(stack);
	s_del(&tmp);
	va_end(p->ap);
	free(p);
	return (s_len(*out));
}
