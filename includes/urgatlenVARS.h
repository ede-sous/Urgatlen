/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urgatlenVARS.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:04:39 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/15 08:29:10 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URGATLENVARS_H
# define URGATLENVARS_H

typedef struct		s_obj
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	char			letter;
	struct s_obj	*next;
	struct s_obj	*prev;
}					t_obj;

typedef struct		s_urgatx
{
	bool			err;
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Event		event;
	TTF_Font		*font;
	t_obj			*head, *tmp, *last;
	const Uint8 	*keys;
}					t_urgatx;

#endif