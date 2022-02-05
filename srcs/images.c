/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:23:57 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/05 21:07:51 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_data *data)
{
	data->wall.image = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &data->wall.w, &data->wall.h);
	data->space.image = mlx_xpm_file_to_image(data->mlx, "images/space.xpm", &data->space.w, &data->space.h);
	data->player.ply_img.image = mlx_xpm_file_to_image(data->mlx, "images/player.xpm", &data->player.ply_img.w, &data->player.ply_img.h);
	data->exit.image = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", &data->exit.w, &data->exit.h);
	data->collec.image = mlx_xpm_file_to_image(data->mlx, "images/collec.xpm", &data->collec.w, &data->collec.h);
	if(!data->wall.image || !data->space.image)
	{
		printf("Error\nInvalid images !");
		exit(1);
	}
}

void	set_images(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while(i < data->map->h)
	{
		j = 0;
		while(j < data->map->w)
		{
			if(data->map->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall.image, j * 64, i * 64);
			else if(data->map->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->space.image, j * 64, i * 64);
			else if(data->map->map[i][j] == 'C'){
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collec.image, j * 64, i * 64);
			}
			else if(data->map->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit.image, j * 64, i * 64);
			else if(data->map->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->space.image, j * 64, i * 64);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player.ply_img.image, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
