/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:09:37 by ldedier           #+#    #+#             */
/*   Updated: 2018/08/14 22:17:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_template.h"

void	ft_process_events(t_env *e)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN &&
				event.key.keysym.sym == SDLK_ESCAPE))
			e->active = 0;
		else if (event.type == SDL_KEYDOWN && !event.key.repeat)
			ft_process_keydown(e, event.key.keysym.sym);
		else if (event.type == SDL_KEYUP)
			ft_process_keyup(e, event.key.keysym.sym);
		else if (event.type == SDL_MOUSEBUTTONDOWN && !event.key.repeat)
			ft_process_mousedown(e, event.key.keysym.sym);
		else if (event.type == SDL_MOUSEBUTTONUP)
			ft_process_mouseup(e, event.key.keysym.sym);
	}
	ft_process_keyboard(e, SDL_GetKeyboardState(NULL));
	ft_process_mouse(e, SDL_GetMouseState(NULL, NULL));
}

void	ft_loop(t_env *e)
{
	float framerate_delay;

	framerate_delay = 1000 / (double)CAPPED_FRAMERATE;
	e->framerate.ms_counter = SDL_GetTicks();
	while (e->active)
	{
		ft_process_delta_first(&(e->framerate));
		ft_process_events(e);
		ft_process(e);
		ft_render_cpu(e);
		ft_process_delta(&(e->framerate));
		SDL_Delay(ft_max(0, framerate_delay - e->framerate.delta));
		ft_print_fps(&(e->framerate));
	}
}
