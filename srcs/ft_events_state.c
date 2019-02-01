/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:35:01 by ldedier           #+#    #+#             */
/*   Updated: 2019/01/29 16:35:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_template.h"

void	ft_process_keyboard(t_env *e, const Uint8* keys)
{
	if (keys[SDL_SCANCODE_RIGHT])
		e->player.pos.x += 10;
	if (keys[SDL_SCANCODE_LEFT])
		e->player.pos.x -= 10;
	if (keys[SDL_SCANCODE_UP])
		e->player.pos.y -= 10;
	if (keys[SDL_SCANCODE_DOWN])
		e->player.pos.y += 10;
}

void	ft_process_mouse(t_env *e, Uint32 keys)
{

}
