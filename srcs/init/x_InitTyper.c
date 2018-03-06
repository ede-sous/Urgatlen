/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_InitTyper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:43:50 by ede-sous          #+#    #+#             */
/*   Updated: 2018/03/06 06:58:31 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		CMD + P => Create file with the current text.
*/

#include "urgatlen.h"

int				x_CheckoutKey(t_urgatx *type)
{
	if (type->EventKeyCode == 19 && (type->EventKeyMod == KMOD_RGUI || type->EventKeyMod == KMOD_LGUI))
	{
		printf("\033[92m Creating file ...\033[0m\n");
		if (!(x_CreateFile(type)))
			return (0);
	}

	else if (type->EventKeyCode >= 89 && type->EventKeyCode <= 98)
		type->EventKeyCode -= 59;

	else if (CONDITION_GOOD_CHAR && !x_ValidChar(type))
			return (0);

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
