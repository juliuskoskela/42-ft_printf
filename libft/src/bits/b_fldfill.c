/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fldfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:23:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/01/03 01:26:26 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int				b_fldfill(uint64_t *field, char *file, char one, uint64_t size)
{
	char		*line;
	int			r;
	int			fd;
	uint64_t	i;

	fd = open(file, O_RDONLY);
	i = 0;
	while ((r = fd_readline(fd, &line)) > 0)
	{
		if (r < 0 || fd < 0 || fd > MAX_FD)
			return (0);
		if (line[0])
		{
			field[i] = b_atonb(line, one, size);
			free(line);
			i++;
		}
	}
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	B_fldfill
**
**	Fill the field from a file. Characters of the value `one` are 1 and all
**	other caracters are 0.
**
**  ----------------------------------------------------------------------------
*/
