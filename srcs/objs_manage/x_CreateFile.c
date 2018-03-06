/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_CreateFile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:43:50 by ede-sous          #+#    #+#             */
/*   Updated: 2018/03/06 06:48:07 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

int				x_CreateFile(t_urgatx *type)
{
	FILE		*fp;
	static int	i = 0;
	char		*name;

	if (!(name = (char*)malloc(sizeof(char) * 50)))
		return (dprintf(2, "Malloc failed x_CreateFile -> l: 19\n"));

	if (access(TEXT_DIR, F_OK | W_OK | R_OK) < 0 &&
			mkdir(TEXT_DIR, S_IRWXU | S_IRWXG | S_IRWXO) < 0)
	{
		x_strdel(&name);
		return (dprintf(2, "Problem creating file ...\n"));
	}

	sprintf(name, "%s/%s%d.txt", TEXT_DIR, TEXT_FILE, i);

	while (access(name, F_OK) >= 0)
	{
		bzero(name, 50);
		sprintf(name, "%s/%s%d.txt", TEXT_DIR, TEXT_FILE, ++i);
	}

	if (!(fp = fopen(name, "a+")))
	{
		x_strdel(&name);
		return (dprintf(2, "Fopen failed x_CreateFile -> l: 37\n"));
	}

	type->tmp = type->head;
	while (type->tmp)
	{
		fprintf(fp, "%c", type->tmp->letter[0]);
		type->tmp = type->tmp->next;
	}
	fprintf(fp, "\n");
	fclose(fp);

	printf("\033[92m File creates -> %s !\033[0m\n", name);
	x_strdel(&name);
	return (1);
}

void			x_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
