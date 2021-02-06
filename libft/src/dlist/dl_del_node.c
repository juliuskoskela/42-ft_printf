/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:05:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void		dl_del_node(t_dlist **ref, t_dlist *del)
{
	if (*ref == NULL || del == NULL)
		return ;
	if (*ref == del)
		*ref = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	else
	{
		free(del);
		del = NULL;
		return ;
	}
	free(del);
}

/*
**  ----------------------------------------------------------------------------
**
**	Dl_del_node
**
**	Delete node `del` in the list.
**
**  ----------------------------------------------------------------------------
*/
