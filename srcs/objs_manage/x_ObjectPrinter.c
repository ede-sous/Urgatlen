/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ObjectPrinter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:43:50 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/27 10:16:22 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

static int		x_SetPosition(t_urgatx *type, t_obj *tmp, int y)
{
	SDL_Rect	pos = (SDL_Rect) { 0, y, 0, 0};

	tmp = type->head;
	while (tmp)
	{
		if (tmp->letter[0] == 10)
		{
			(pos.y += (CHAR_SIZE * 2)) && !(pos.x = 0);
			if (pos.y + (CHAR_SIZE * 2) >= WIN_HEIGHT)
				return (x_SetPosition(type, NULL, y - (CHAR_SIZE * 2)));
			tmp->pos = pos;
			tmp = tmp->next;
			continue ;
		}

		pos.x += (!pos.x ? 5 : pos.w + 2);
		(tmp->letter[0] == 32 ? (pos.x += (CHAR_SIZE / 2)) : 0);

		if (TTF_SizeText(type->font, tmp->letter, &pos.w, &pos.h) < 0)
			(pos.w = (CHAR_SIZE)) && (pos.h = CHAR_SIZE);

		if (pos.x + pos.w >= WIN_WIDTH && (pos.x = 5))
			pos.y += (CHAR_SIZE * 2);

		if (pos.y + (CHAR_SIZE * 2) >= WIN_HEIGHT)
			return (x_SetPosition(type, NULL, y - (CHAR_SIZE * 2)));

		tmp->pos = pos;
		tmp = tmp->next;
	}
	return (1);
}

void			x_RenderCopy(t_urgatx *type, t_obj *tmp)
{
	if (!type->head)
		return ;

	x_SetPosition(type, NULL, 0);

	tmp = type->head;
	while (tmp)
	{
		if (tmp->pos.y >= 0 && tmp->letter[0] != 10)
			SDL_RenderCopyEx(type->render, tmp->texture, NULL, &tmp->pos, 0, NULL, 0);
		// else if (tmp->pos.y >= 0)
		// 	SDL_RenderCopyEx(type->render, tmp->texture, NULL,)

		tmp = tmp->next;
	}
}
