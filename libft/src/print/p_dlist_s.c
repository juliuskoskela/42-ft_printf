/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_dlist_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:57:01 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/29 17:33:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void			p_dlist_s(t_dlist **list)
{
	if (!(*list))
		p_str("error: `NULL` pointer in p_dlist_s.\n");
	while (*list)
	{
		p_str((char *)(*list)->content);
		p_char('\n');
		*list = (*list)->next;
	}
}

/*
**  ----------------------------------------------------------------------------
**
**	P_dlist_s
**
**	Print the contents of list with void content as char strings.
**
**  ----------------------------------------------------------------------------
*/
