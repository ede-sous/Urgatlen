/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ObjectPrinter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:43:50 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/18 23:34:36 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"


void			x_RenderCopy(t_urgatx *type, t_obj *tmp)
{
	SDL_Rect	pos = (SDL_Rect){ 0, 0, 0, 0};

	if (!type->head)
		return ;

	tmp = type->head;
	while (tmp)
	{
		if (tmp->letter == 10)
		{
			(pos.y += 30) && !(pos.x = 0);
			tmp = tmp->next;
			continue ;
		}
		pos.x += (!pos.x ? 5 : pos.w + 2);
		(tmp->letter == 32 ? (pos.x += 5) : 0);

		if (TTF_SizeText(type->font, &tmp->letter, &pos.w, &pos.h) < 0)
			(pos.w = 10) && (pos.h = 15);

		if (pos.x + pos.w >= WIN_WIDTH && (pos.x = 5))
			pos.y += 30;
		if (pos.y + 30 >= WIN_HEIGHT)
			return ;

		SDL_RenderCopyEx(type->render, tmp->texture, NULL, &pos, 0, NULL, 0);
		tmp = tmp->next;
	}
}
