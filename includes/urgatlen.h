/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urgatlen.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:11:39 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/15 07:47:43 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URGATLEN_H
# define URGATLEN_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

# include "urgatlenCONST.h"
# include "urgatlenVARS.h"


/*
**				Init Functions
*/

int				x_InitTyper(t_urgatx *type);
t_urgatx		x_InitSDL(void);

/*
**				Object Functions
*/

int				x_AddChar(t_urgatx *type);
int				x_DelChar(t_urgatx *type);
int				x_FillObjectInfo(t_urgatx *type);
void			x_RenderCopy(t_urgatx *type, t_obj *tmp);

/*
**				Key Management Functions
*/

int				x_ValidChar(t_urgatx *type);
int				x_ValidKey(t_urgatx *type);
void			x_KeyToChar(t_urgatx *type);

/*
**				Parser functions
*/

int				**x_readtoi(char *path);

#endif
