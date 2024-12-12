/* *************************************************************************************** */
/*                                                                                         */
/*    vscode-sam-header                               ::::::::       :::        :::   :::  */
/*                                                  :+:    :+:    :+: :+:     :+:+: :+:+:  */
/*    By: sam                                      +:+          +:+   +:+   +:+ +:+:+ +:+  */
/*    <sam.astier-gacon@lycee-berthollet.com>     +#++:++#++  +#++:++#++:  +#+  +:+  +#+   */
/*                                                      +#+  +#+     +#+  +#+       +#+    */
/*    Created: 2024-12-12 18:38:43              #+#    #+#  #+#     #+#  #+#       #+#     */
/*    Updated: 2024-12-12 18:38:43              ########   ###     ###  ###       ###      */
/*                                                                                         */
/* *************************************************************************************** */

#include "so_long.h"

void	update_prev_state(t_data *all)
{
	int	i = 0;
	int	j = 0;

	while (i < all->width_grid)
	{
		while (j < all->length_grid)
		{
			all->grid[i][j].prev_state = all->grid[i][j].state;
			if (all->grid[i][j].state == 1)
				mlx_put_image_to_window(all->mlx, all->win, all->b_square, j * all->pixel_size, i * all->pixel_size);
			else
				mlx_put_image_to_window(all->mlx, all->win, all->w_square, j * all->pixel_size, i * all->pixel_size);
			j++;
		}
		i++;
		j = 0;
	}
}

int	get_around(int x, int y, t_case **grid, t_data *all)
{
	int	count = 0;

	if (x != 0)
	{
		for (int i = y-1; i < y+2; i++)
		{
			if (i > 0 && i < all->length_grid)
				count += grid[x-1][i].prev_state;
		}
	}
	if (y > 0)
	{
		count += grid[x][y-1].prev_state;
	}
	if (y < all->length_grid)
	{
		count += grid[x][y+1].prev_state;
	}
	if (x + 1 < all->width_grid)
	{
		for (int i = y-1; i < y+2; i++)
		{
			if (i > 0 && i < all->length_grid)
				count += grid[x+1][i].prev_state;
		}
	}
	return (count);
}

void	update_state(t_data *all)
{
	int	count;
	int	i = 0;
	int	j = 0;

	while (i < all->width_grid)
	{
		while (j < all->length_grid)
		{
			count = get_around(i, j, all->grid, all);
			if (count == 3)
				all->grid[i][j].state = 1;
			else if (count == 2 && all->grid[i][j].prev_state == 1)
				all->grid[i][j].state = 1;
			else
				all->grid[i][j].state = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

int	update_win(t_data *all)
{
	if (all->game_state == 0)
		return (0);
	all->frame++;
	if (all->frame % all->frame_rate == 0)
	{
		update_state(all);
		update_prev_state(all);
		all->frame = 0;
		if (all->game_state == 2)
			all->game_state = 0;
	}
	return (0);
}
