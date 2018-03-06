/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_KeyCharModifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 07:50:28 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/27 10:13:17 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

static int		x_GetHiggerCode(SDL_Scancode code)
{
	switch (code)
	{
		case (SDL_SCANCODE_1) :
			return ('!');

		case (SDL_SCANCODE_2) :
			return ('@');

		case (SDL_SCANCODE_3) :
			return ('#');

		case (SDL_SCANCODE_4) :
			return ('$');

		case (SDL_SCANCODE_5) :
			return ('%');

		case (SDL_SCANCODE_6) :
			return ('^');

		case (SDL_SCANCODE_7) :
			return ('&');

		case (SDL_SCANCODE_8) :
			return ('*');

		case (SDL_SCANCODE_9) :
			return ('(');

		case (SDL_SCANCODE_0) :
			return (')');

		default :
			return (code + 19);
	}
	return (code + 19);
}

void			x_KeyToChar(t_urgatx *type)
{
	if (type->EventKeyCode >= SDL_SCANCODE_A
			&& type->EventKeyCode <= SDL_SCANCODE_Z)
	{
		type->EventKeyCode -= 4;
		if ((type->EventKeyMod >= LSHIFT && type->EventKeyMod <= LRSHIFT)
				|| type->EventKeyMod == CAPSLOCK)
			type->EventKeyCode += 'A';
		
		else if (!type->EventKeyMod ||
					(type->EventKeyMod >= CAPSLOCK_LSHIFT
					&& type->EventKeyMod <= CAPSLOCK_LRSHIFT))
			type->EventKeyCode += 'a';
		
		else return ;
	}

	else if ((!type->EventKeyMod || type->EventKeyMod == CAPSLOCK)
				&& type->EventKeyCode >= SDL_SCANCODE_1
				&& type->EventKeyCode <= SDL_SCANCODE_0)
			type->EventKeyCode += (type->EventKeyCode == SDL_SCANCODE_0 ? 9 : 19);

	else if (type->EventKeyCode >= SDL_SCANCODE_1
				&& type->EventKeyCode <= SDL_SCANCODE_0)
		type->EventKeyCode = x_GetHiggerCode(type->EventKeyCode);

//	printf("|letter = %c|Mod = %d|\n", type->EventKeyCode, type->EventKeyMod);
}
