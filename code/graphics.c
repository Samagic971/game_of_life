/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:17:42 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/30 18:17:43 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_sprite(t_data *all)
{
    all->b_square = mlx_new_image(all->mlx, all->pixel_size, all->pixel_size);
    all->b_square_addr = mlx_get_data_addr(all->b_square, &all->bits_per_pixel, &all->size_line, &all->endian);
    for (int y = 0; y < all->pixel_size; y++) {
        for (int x = 0; x < all->pixel_size; x++) {
            int pixel_index = (y * all->size_line) + (x * (all->bits_per_pixel / 8));
            all->b_square_addr[pixel_index] = 0x00;
            all->b_square_addr[pixel_index + 1] = 0x00;
            all->b_square_addr[pixel_index + 2] = 0x00;
            all->b_square_addr[pixel_index + 3] = 0x00;
        }
    }
    all->w_square = mlx_new_image(all->mlx, all->pixel_size, all->pixel_size);
    all->w_square_addr = mlx_get_data_addr(all->w_square, &all->bits_per_pixel, &all->size_line, &all->endian);
    for (int y = 0; y < all->pixel_size; y++) {
        for (int x = 0; x < all->pixel_size; x++) {
            int pixel_index = (y * all->size_line) + (x * (all->bits_per_pixel / 8));
            all->w_square_addr[pixel_index] = 0xFF;
            all->w_square_addr[pixel_index + 1] = 0xFF;
            all->w_square_addr[pixel_index + 2] = 0xFF;
            all->w_square_addr[pixel_index + 3] = 0x00;
        }
    }
	all->w_rect = mlx_new_image(all->mlx, all->screen_x, all->screen_y);
    all->w_rect_addr = mlx_get_data_addr(all->w_rect, &all->bits_per_pixel, &all->size_line, &all->endian);
    for (int y = 0; y < all->screen_y; y++) {
        for (int x = 0; x < all->screen_x; x++) {
            int pixel_index = (y * all->size_line) + (x * (all->bits_per_pixel / 8));
            all->w_rect_addr[pixel_index] = 0xFF;
            all->w_rect_addr[pixel_index + 1] = 0xFF;
            all->w_rect_addr[pixel_index + 2] = 0xFF;
            all->w_rect_addr[pixel_index + 3] = 0x00;
        }
    }
}

void	launch(t_data *all)
{
	all->mlx = mlx_init();
	all->screen_y = all->width_grid * all->pixel_size;
	all->screen_x = all->length_grid * all->pixel_size;
	init_sprite(all);
	all->win = mlx_new_window(all->mlx, all->screen_x, all->screen_y, \
		"Game of life");
	mlx_put_image_to_window(all->mlx, all->win, all->w_rect, 0, 0);
	mlx_do_sync(all->mlx);
	mlx_hook(all->win, 4, 0, put_square, all);
	mlx_hook(all->win, 17, 0, (void *)close_window, all);
    mlx_hook(all->win, 2, 1L << 0, hook_event, all);
    mlx_loop_hook(all->mlx, update_win, all);
	mlx_loop(all->mlx);
}
