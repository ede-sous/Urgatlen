/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_InitSDL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:40:15 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/18 23:33:57 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

t_urgatx		x_InitSDL(void)
{
	t_urgatx	tmp = { false,
						NULL, NULL, 0,
						NULL, NULL, NULL, NULL,
						SDL_GetKeyboardState(NULL)};

	if ((SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() < 0) && SDL_ERROR)
		return (tmp);
	if ((tmp.win = SDL_CreateWindow("Urgatlen Typer",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL
			&& SDL_ERROR)
		return (tmp);
	if ((tmp.render = SDL_CreateRenderer(tmp.win, -1, SDL_RENDERER_ACCELERATED)) == NULL && SDL_ERROR)
		return (tmp);
	if (!(tmp.font = TTF_OpenFont(USING_FONT, 30)) && SDL_ERROR)
		return (tmp);
    SDL_SetRenderDrawColor(tmp.render, 0, 0, 0, 255);
	tmp.err = true;
	return (tmp);
}
