/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 02:54:57 by jkoskela          #+#    #+#             */
/*   Updated: 2021/02/06 02:39:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int					st_push(t_stack **head, void *value)
{
	t_stack			*newnode;

	if (!(newnode = (t_stack *)malloc(sizeof(t_stack))))
		return (-1);
	newnode->content = value;
	newnode->next = *head;
	*head = newnode;
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	St_push
**
**	Push to the stack.
**
**  ----------------------------------------------------------------------------
*/
