/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:30:27 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/26 20:01:50 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx.h"
# include "libft/ft_printf.h"
# define PROB_GRID "Problem with grid (Number of smth or not rectangle)\
 or path not valid"

typedef	struct s_case
 {
	int		state;
	int		prev_state;
 }				t_case;
 

typedef struct s_data
{
	void	*mlx;
	void	*win;

	t_case	**grid;
	int		width_grid;
	int		length_grid;

	void	*b_square;
	char	*b_square_addr;
	void	*w_square;
	char	*w_square_addr;
	void	*w_rect;
	char	*w_rect_addr;
	int		temp;

	int		bits_per_pixel;
    int		size_line;
    int		endian;

	int		pixel_size;
	int		game_state;
	int		frame;
	int		frame_rate;

	int		screen_x;
	int		screen_y;
}			t_data;

t_case	**create_array(int l, int w, t_data *all);

//utils.c
void	ft_print_array(char **array);

//graphics.c
int		put_square(int button, int x, int y, t_data *all);
void	launch(t_data *all);
void	close_window(t_data *all);
int		hook_event(int keydown, t_data *all);

int		update_win(t_data *all);
void	reset_game(t_data *all);

#endif
