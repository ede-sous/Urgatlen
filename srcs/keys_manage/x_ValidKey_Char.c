/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ValidKey_Char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 07:48:54 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/27 10:18:20 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

int				x_ValidChar(t_urgatx *type)
{
	x_KeyToChar(type);

	if (TTF_GlyphIsProvided(type->font, type->EventKeyCode) && !(x_AddChar(type)))
		return (0);

	return (1);
}

int				x_ValidKey(t_urgatx *type)
{

	switch (type->EventKeyCode)
	{

///		---> Simple Input

		case (SDL_SCANCODE_BACKSPACE) :
			return (type->head ? x_DelChar(type) : 1);

		case (SDL_SCANCODE_RETURN) :
			type->EventKeyCode = '\n';
			break;

		case (SDL_SCANCODE_SPACE) :
			type->EventKeyCode = ' ';
			break;

///		---> Multiple Input

		case (SDL_SCANCODE_GRAVE):
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '~' : '`';
			break ;

		case (SDL_SCANCODE_MINUS) :
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '_' : SDL_SCANCODE_MINUS;
			break ;

		case (SDL_SCANCODE_EQUALS) :
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '+' : '=';
			break ;

		case (SDL_SCANCODE_LEFTBRACKET):
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '{' : '[';
			break;

		case (SDL_SCANCODE_RIGHTBRACKET):
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '}' : ']';
			break;

		case (SDL_SCANCODE_BACKSLASH) :
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '|' : '\\';
			break;

		case (SDL_SCANCODE_SEMICOLON) :
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? ':' : ';';
			break ;

		case (SDL_SCANCODE_APOSTROPHE) :
			if (USING_FONT == URGATLEN_FONT)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '\"' : '\'';
			break;

		case (SDL_SCANCODE_PERIOD):
			if (USING_FONT == URGATLEN_FONT && type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '>' : '.';
			break ;

		case (SDL_SCANCODE_COMMA):
			if (USING_FONT == URGATLEN_FONT && type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
				return (1);		
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '<' : ',';
			break ;

		case (SDL_SCANCODE_SLASH):
			if (USING_FONT == URGATLEN_FONT && type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
				return (1);
			type->EventKeyCode = (type->EventKeyMod > 0 && type->EventKeyMod != CAPSLOCK)
									? '?' : '/';
			break;

		default :
			return (1);
	}

	if (!(x_AddChar(type)))
		return (0);

	return (1);
}
