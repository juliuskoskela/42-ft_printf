/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_putafter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:01:40 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		dl_putafter(t_dlist **ref, t_dlist *prev, void *new)
{
	t_dlist	*new_node;

	if (prev == NULL)
		return ;
	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	new_node->content = new;
	new_node->next = prev->next;
	prev->next = new_node;
	new_node->prev = prev;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	else
		(*ref) = new_node;
}

/*
**  ----------------------------------------------------------------------------
**
**	Dl_putafter
**
**	Put node `new` after node `prev` in the list.
**
**  ----------------------------------------------------------------------------
*/
