/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:09:19 by ldedier           #+#    #+#             */
/*   Updated: 2018/08/14 20:09:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_template.h"

int main(int argc, char **argv)
{
	t_env e;

	(void)argc;
	(void)argv;
	if (ft_init_all(&e))
		return (1);
	ft_loop(&e);
	return (0);
}
