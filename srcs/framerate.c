/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framerate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:42:38 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/09 19:56:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_template.h"

void	ft_process_delta_first(t_framerate *framerate)
{
	framerate->previous = SDL_GetPerformanceCounter();
}

void	ft_process_delta(t_framerate *framerate)
{
	framerate->current = SDL_GetPerformanceCounter();
	framerate->delta = (double)(((framerate->current - framerate->previous) *
				1000)) / SDL_GetPerformanceFrequency();
	framerate->fps_counter++;
}

void	ft_print_fps(t_framerate *framerate)
{
	if (SDL_GetTicks() - framerate->ms_counter > 1000)
	{
		framerate->ms_counter = SDL_GetTicks();
		printf("fps : %d (%d)\n",
				ft_min(60, framerate->fps_counter), framerate->fps_counter);
		framerate->fps_counter = 0;
	}
}
