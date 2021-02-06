/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:06:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		dl_del_last(t_dlist **ref)
{
	t_dlist	*current;

	if (*ref == NULL)
		return ;
	current = *ref;
	while (current->next)
		current = current->next;
	dl_del_node(ref, current);
}

/*
**  ----------------------------------------------------------------------------
**
**	Dl_del_last
**
**	Delete las node in the list.
**
**  ----------------------------------------------------------------------------
*/
