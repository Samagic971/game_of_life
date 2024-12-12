/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:59:38 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/27 12:59:41 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_line(t_case *array, int l)
{
	int i = 0;

	while (i < l)
	{
		array[i].state = 0;
		array[i].prev_state = 0;
		i++;
	}
}

t_case	**create_array(int l, int w, t_data *all)
{
	t_case	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(t_case *) * w);
	if (!array)
		return (NULL);
	while (i < w)
	{
		array[i] = malloc(sizeof(t_case) * l);
		if (!(array[i]))
			return (NULL);
		init_line(array[i], l);
		i++;
	}
	all->width_grid = w;
	all->length_grid = l;
	return (array);
}
