/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:20:37 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 16:20:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_template.h"

void	ft_set_dimensions(t_sdl *sdl)
{
	SDL_DisplayMode dm;

	SDL_GetCurrentDisplayMode(0, &dm);
	sdl->screen.w = dm.w;
	sdl->screen.h = dm.h;
}

int		ft_init_sdl_2(t_sdl *sdl)
{
	if (!(sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0)))
		return (1);
	if (!(sdl->w_surface = SDL_CreateRGBSurface(0, sdl->screen.w,
				sdl->screen.h, 32, 0, 0, 0, 0)))
		return (1);
	if (SDL_RenderSetLogicalSize(sdl->renderer, sdl->screen.w,
				sdl->screen.h) < 0)
		return (1);
	if (SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255) < 0)
		return (1);
	return (0);
}

int		ft_init_sdl(t_sdl *sdl)
{
	sdl->screen.x = 0;
	sdl->screen.y = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (1);
	ft_set_dimensions(sdl);
	if (TTF_Init() < 0)
		return (1);
	 if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		 return (0);
	 Mix_VolumeMusic(32);
	 if (!(sdl->window = SDL_CreateWindow("sdl_template", sdl->screen.x,
			sdl->screen.y, sdl->screen.w, sdl->screen.h,
				SDL_WINDOW_FULLSCREEN_DESKTOP)))
		 return (1);
	if (ft_init_sdl_2(sdl))
		return (1);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	return (0);
}

void	ft_init_world(t_env *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
}

int		ft_init_all(t_env *e)
{
	if (ft_init_sdl(&(e->sdl)))
		return (1);
	e->active = 1;
	e->framerate.previous = SDL_GetPerformanceCounter();
	ft_init_world(e);
	return (0);
}
