/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:30:17 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/26 20:00:36 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_data	all;

	all.grid = NULL;
	all.game_state = 0;
	// *****  Parameters for the game *****
	all.pixel_size = 10;
	all.frame = 0;
	all.frame_rate = 1000;
	// *****   ******
	if (ac != 3)
	{
		ft_printf("Do ./game_of_life <length> <width> \n");
		return (0);
	}
	all.grid = create_array(ft_atoi(av[1]), ft_atoi(av[2]), &all);
	if (!all.grid)
		return (0);
	launch(&all);
	return (0);
}
