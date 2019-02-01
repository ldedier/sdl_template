/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_template.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:30:34 by ldedier           #+#    #+#             */
/*   Updated: 2019/01/29 16:30:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_TEMPLATE_H
# define SDL_TEMPLATE_H

# include "libft.h"
# include "libmat.h"
# include <stdlib.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_mixer/SDL_mixer.h>
# include <SDL2_net/SDL_net.h>

# define CAPPED_FRAMERATE 60
# define BACKGROUND_COLOR 0x000000

typedef struct				s_sdl
{
	SDL_Surface				*w_surface;
	SDL_Surface				*surface;
	SDL_Texture				*texture;
	SDL_Rect				screen;
	SDL_Window				*window;
	SDL_Renderer			*renderer;
}							t_sdl;

typedef struct				s_player
{
	t_ivec2					pos;
}							t_player;

typedef struct				s_framerate
{
	Uint64					current;
	Uint64					previous;
	double					delta;
	Uint32					ms_counter;
	int						fps_counter;
}							t_framerate;

typedef struct				s_env
{
	t_sdl					sdl;
	t_player				player;
	t_framerate				framerate;
	char					active;
}							t_env;

int							ft_init_all(t_env *e);
void						ft_loop(t_env *e);
void						ft_process_keydown(t_env *e, SDL_Keycode code);
void						ft_process_keyup(t_env *e, SDL_Keycode code);
void						ft_process_mousedown(t_env *e, SDL_Keycode code);
void						ft_process_mouseup(t_env *e, SDL_Keycode code);
void						ft_process_keyboard(t_env *e, const Uint8* keys);
void						ft_process_mouse(t_env *e, Uint32 keys);
void						ft_render_gpu(t_env *e);
int							ft_render_cpu(t_env *e);
void						ft_process(t_env *e);
void						ft_process_delta_first(t_framerate *framerate);
void						ft_process_delta(t_framerate *framerate);
void						ft_print_fps(t_framerate *framerate);
#endif
