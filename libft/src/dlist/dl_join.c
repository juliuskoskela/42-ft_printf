/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:09:24 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/05 18:10:51 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_dlist			*dl_join(t_dlist *head, t_dlist *tail)
{
	t_dlist		*out;

	out = head;
	while (head->next)
		head = head->next;
	head->next = tail;
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	Dl_join
**
**	Join lists so that the last node of `head` points to the first node of
**	`tail`.
**
**  ----------------------------------------------------------------------------
*/
