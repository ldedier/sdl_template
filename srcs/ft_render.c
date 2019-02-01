/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 21:46:38 by ldedier           #+#    #+#             */
/*   Updated: 2018/08/14 22:02:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_template.h"

void	ft_render_world_gpu(t_env *e)
{
	SDL_Rect rect;

	rect.w = 100;
	rect.h = 100;
	rect.x = e->player.pos.x;
	rect.y = e->player.pos.y;
	SDL_SetRenderDrawColor(e->sdl.renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(e->sdl.renderer, &rect);
}

int	ft_render_world_cpu(t_env *e)
{
	SDL_Rect rect;

	rect.w = 100;
	rect.h = 100;
	rect.x = e->player.pos.x;
	rect.y = e->player.pos.y;
	if (SDL_FillRect(e->sdl.w_surface, &rect, 0xFF0000))
		return (1);
	return (0);
}

void	ft_render_gpu(t_env *e)
{
	SDL_SetRenderDrawColor(e->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(e->sdl.renderer);
	ft_render_world_gpu(e);
	SDL_RenderPresent(e->sdl.renderer);
}

int		ft_render_cpu(t_env *e)
{
	SDL_FillRect(e->sdl.w_surface, NULL, BACKGROUND_COLOR);
	if (ft_render_world_cpu(e))
		return (1);
	e->sdl.texture = SDL_CreateTextureFromSurface(e->sdl.renderer,
		e->sdl.w_surface);
	SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, NULL, NULL);
	SDL_DestroyTexture(e->sdl.texture);
	SDL_RenderPresent(e->sdl.renderer);
	return (0);
}
