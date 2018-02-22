/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urgatlen.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 23:11:39 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/21 06:19:48 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URGATLEN_H
# define URGATLEN_H

#ifdef _WIN32
        #include <SDL2/SDL.h>
        #include <SDL2/SDL_image.h>
        #include <SDL2/SDL_ttf.h>
        #include <SDL2/SDL_net.h>
#elif __APPLE__
        #include <SDL.h>
        #include <SDL_image.h>
        #include <SDL_ttf.h>
        #include <SDL_net.h>
#else
#   error "Unknown compiler"
#endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "urgatlenVARS.h"
# include "urgatlenCONST.h"
# include "urgatlenFunctions.h"

#endif
