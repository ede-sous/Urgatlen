/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:03:39 by ede-sous          #+#    #+#             */
/*   Updated: 2018/02/15 07:54:10 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "urgatlen.h"

int				main(void)
{
	t_urgatx	type;

	type = x_InitSDL();
	if (type.err == false)
		return (1);
	return (x_InitTyper(&type));
}
