/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 01:51:48 by jkoskela          #+#    #+#             */
/*   Updated: 2020/10/23 00:17:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void			dl_rotate(t_dlist **head_ref, uint64_t n)
{
	t_dlist		*current;
	t_dlist		*node;
	uint64_t	count;

	if (n == 0)
		return ;
	current = *head_ref;
	count = 1;
	while (count < n && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return ;
	node = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	(*head_ref)->prev = current;
	*head_ref = node->next;
	(*head_ref)->prev = NULL;
	node->next = NULL;
}

/*
**  ----------------------------------------------------------------------------
**
**	Dl_protate
**
**	Rotate list by `n` steps.
**
**  ----------------------------------------------------------------------------
*/
