/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_AddDelChar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 07:51:11 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/27 10:05:20 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

int				x_AddChar(t_urgatx *type)
{
	if (!type->head)
	{
		if (!(type->last = (t_obj*)malloc(sizeof(t_obj))))
			return (0);

		type->head = type->last;
		type->last->prev = NULL;
	}

	else
	{
		type->tmp = type->last;
		type->last = type->last->next;
	
		if (!(type->last = (t_obj*)malloc(sizeof(t_obj))))
			return (0);
	
		type->tmp->next = type->last;
		type->last->prev = type->tmp;
	}
	
	type->last->next = NULL;
	return (x_FillObjectInfo(type));
}

int				x_DelChar(t_urgatx *type)
{
	type->tmp = type->last;
	type->last = type->last->prev;
	(type->last ? (type->last->next = NULL) : (type->head = NULL));

	bzero(type->tmp->letter, 2);
	type->tmp->prev = NULL;
	
	SDL_DestroyTexture(type->tmp->texture);
	free(type->tmp);
	
	type->tmp = NULL;
	return (1);
}
