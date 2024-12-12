/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:39:30 by sastier-          #+#    #+#             */
/*   Updated: 2024/05/01 12:39:32 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->width_grid)
	{
		free(all->grid[i]);
		i++;
	}
	free(all->grid);
}

void	close_window(t_data *all)
{
	free_array(all);
	mlx_destroy_window(all->mlx, all->win);
	exit(0);
}

int	put_square(int button, int x, int y, t_data *all)
{
	int	x_adapt;
	int	y_adapt;
	int	state;

	if (button < 2)
		;
	if (x < 0 || y < 0 || y > all->screen_y ||x > all->screen_x || all->game_state != 0)
		return (-1);
	state = ((all->grid[y / all->pixel_size][x / all->pixel_size].state) + 1) % 2;
	x_adapt = x - x % all->pixel_size;
	y_adapt = y - y % all->pixel_size;
	all->grid[y / all->pixel_size][x / all->pixel_size].state = state;
	all->grid[y / all->pixel_size][x / all->pixel_size].prev_state = state;
	if (state == 1)
		mlx_put_image_to_window(all->mlx, all->win, all->b_square, x_adapt, y_adapt);
	else
		mlx_put_image_to_window(all->mlx, all->win, all->w_square, x_adapt, y_adapt);
	return (0);
}

void	reset_game(t_data *all)
{
	int	i = 0;
	int	j = 0;

	mlx_put_image_to_window(all->mlx, all->win, all->w_rect, 0, 0);
	while (i < all->width_grid)
	{
		while (j < all->length_grid)
		{
			all->grid[i][j].prev_state = 0;
			all->grid[i][j].state = 0;
			j++;
		}
		i++;
		j = 0;
	}
	all->game_state = 0;
}

int	hook_event(int keydown, t_data *all)
{
	if (keydown == 53 || keydown == 0)
		close_window(all);
	if (keydown == 35)
		all->game_state = 0;
	if (keydown == 15)
		reset_game(all);
	if (keydown == 126)
		all->frame_rate = all->frame_rate * 9 / 10;
	if (keydown == 125)
		all->frame_rate = all->frame_rate * 11 / 10;
	if (keydown == 45)
	{
		all->game_state = 2;
		all->frame = all->frame_rate - 1;
	}
	if (keydown == 1)
		all->game_state = 1;
	return (1);
}
