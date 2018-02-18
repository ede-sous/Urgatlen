/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_InitTyper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:43:50 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/16 01:21:58 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

int				x_CheckoutKey(t_urgatx *type)
{
	if (CONDITION_GOOD_CHAR)
	{
		if (!x_ValidChar(type))
			return (0);
	}

	else if (!x_ValidKey(type))
		return (0);

	type->EventKeyCode = 0;
	return (1);
}

int				x_InitTyper(t_urgatx *type)
{
	while (CONDITION_ESCAPE)
	{
		if (type->event.type == SDL_KEYDOWN && !x_CheckoutKey(type))
			return (0);
		x_RenderCopy(type, NULL);
		SDL_RenderPresent(type->render);
        SDL_RenderClear(type->render);
        SDL_Delay(10);
	}
	return (1);
}
