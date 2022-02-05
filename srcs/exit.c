/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:15:21 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/05 18:22:44 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_map(t_data *data)
{

	printf("YOU FINISHED 1");
	int	x;
	int	y;

	y = 0;
	// draw black screen 
	while(y < data->map->h * 64)
	{
		x = 0;
		while(x < data->map->w * 64)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, 755);
			x++;
		}
		y++;
	}

	
	// write score 
	mlx_string_put(data->mlx, data->mlx_win, (data->map->w * 64) / 2, (data->map->h * 64) / 2, 0, "You scored 100 !");
	mlx_string_put(data->mlx, data->mlx_win, (data->map->w * 64) / 2, (data->map->h * 64) / 2 + 40, 0, "PRESS ESC TO EXIT !");

	// free unused pointers !
}
