/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urgatlenFunctions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:11:39 by ede-sous          #+#    #+#             */
/*   Updated: 2018/03/06 06:34:31 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URGATLENFUNCTIONS_H
# define URGATLENFUNCTIONS_H

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
**				File functions
*/

int				x_CreateFile(t_urgatx *type);
void			x_strdel(char **str);

/*
**				Parser functions
*/

int				**x_readtoi(char *path);

#endif