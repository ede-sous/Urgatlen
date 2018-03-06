/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urgatlenCONST.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:13:41 by ede-sous          #+#    #+#             */
/*   Updated: 2018/03/06 06:38:31 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URGATLENCONST_H
# define URGATLENCONST_H

/*
**		Standards Defines
*/

# define WIN_WIDTH				1024
# define WIN_HEIGHT				720

# define TEXT_DIR				"texts"
# define TEXT_FILE				"text_"

/*
**		Font Defines
*/

# define DEFAULT_FONT			"assets/AmericanTypewriter.ttc"
# define URGATLEN_FONT			"assets/Urgatlen.ttf"

# ifdef	URGATLEN
	# define USING_FONT			URGATLEN_FONT
	# define CHAR_SIZE			16
# else
	# define USING_FONT			DEFAULT_FONT
	# define CHAR_SIZE			10
# endif

/*
**		Const Defines
*/

# define LSHIFT					1
# define RSHIFT					2
# define LRSHIFT				3
# define CAPSLOCK				8192
# define CAPSLOCK_LSHIFT		8193
# define CAPSLOCK_RSHIFT		8194
# define CAPSLOCK_LRSHIFT		8195

/*
**		Var Defines
*/

# define EventKeyCode			event.key.keysym.scancode
# define EventKeyMod			event.key.keysym.mod

/*
**		Conditions Defines
*/

# define CONDITION_ESCAPE		((SDL_PollEvent(&type->event) || 1) \
									&& type->event.type != SDL_QUIT \
									&& !type->keys[SDL_SCANCODE_ESCAPE])

# define CONDITION_GOOD_CHAR	(type->EventKeyCode >= SDL_SCANCODE_A \
									&& type->EventKeyCode <= SDL_SCANCODE_0)

//--//	Error Case Define
# define SDL_ERROR				(dprintf(2, "Error:\n %s\n", SDL_GetError()))

#endif
