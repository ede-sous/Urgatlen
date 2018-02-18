/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ModifyObject.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 07:52:53 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/15 07:54:27 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

int				x_FillObjectInfo(t_urgatx *type)
{
	type->last->letter = (char)type->EventKeyCode;

	if (!(type->last->surface = TTF_RenderText_Blended(type->font, &type->last->letter, (SDL_Color){255,255,255,255})))
		return (0);
	
	if (!(type->last->texture = SDL_CreateTextureFromSurface(type->render, type->last->surface)))
		return (0);
	
	SDL_FreeSurface(type->last->surface);
	return (1);
}
