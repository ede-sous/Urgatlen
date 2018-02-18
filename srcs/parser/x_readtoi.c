/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_readtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 00:01:20 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/15 07:54:32 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

typedef struct	s_read
{
	int			x, y, i, fd;
	ssize_t		ret;
	int			**letter;
	char		*buff;
}				t_read;

static int		x_getfilecontent(t_read *rd)
{
	bzero(rd->buff, 17);

	while ((rd->ret = read(rd->fd, rd->buff, 17)) > 0)
	{
		if (!(rd->letter[rd->y] = (int*)malloc(sizeof(int) * 16)))
			return (0);

		while (rd->x < 17)
			rd->letter[rd->y][rd->x] = rd->buff[rd->x++] - 48;
		++rd->y && !(rd->x = 0);
	
		bzero(rd->buff, 17);
	}
	rd->letter[rd->y] = NULL;

	free(rd->buff);
	rd->buff = NULL;
	return (1);
}

int				**x_readtoi(char *path)
{
	t_read		rd = {
							0, 0, 0, open(path, O_RDONLY),
							0,
							(int**)malloc(sizeof(int*) * 17),
							(rd.fd < 0 ? NULL : (char*)malloc(sizeof(char) * 17))
						};

	if (rd.fd < 0 || !rd.buff || !rd.letter)
		return (NULL);

	if (!x_getfilecontent(&rd))
		return (NULL);

	close(rd.fd);
	return (rd.letter);
}
