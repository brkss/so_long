/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:23:57 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/06 19:34:12 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_images(t_data	*data)
{

	data->player.ply_img[0].image = mlx_xpm_file_to_image(data->mlx, "images/player/player_0.xpm", &data->player.ply_img[0].w, &data->player.ply_img[0].h);
	
	data->player.ply_img[1].image = mlx_xpm_file_to_image(data->mlx, "images/player/player_1.xpm", &data->player.ply_img[1].w, &data->player.ply_img[1].h);
	
	data->player.ply_img[2].image = mlx_xpm_file_to_image(data->mlx, "images/player/player_2.xpm", &data->player.ply_img[2].w, &data->player.ply_img[2].h);
	
	data->player.ply_img[3].image = mlx_xpm_file_to_image(data->mlx, "images/player/player_3.xpm", &data->player.ply_img[3].w, &data->player.ply_img[3].h);

	data->player.ply_img[4].image = mlx_xpm_file_to_image(data->mlx, "images/player/player_4.xpm", &data->player.ply_img[4].w, &data->player.ply_img[4].h);

}

void	load_images(t_data *data)
{
	data->wall.image = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm", &data->wall.w, &data->wall.h);
	data->space.image = mlx_xpm_file_to_image(data->mlx, "images/space.xpm", &data->space.w, &data->space.h);
	//data->player.ply_img.image = mlx_xpm_file_to_image(data->mlx, "images/player.xpm", &data->player.ply_img.w, &data->player.ply_img.h);
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
	mlx_clear_window (data->mlx, data->mlx_win);
	put_string(data, 0, 3, 255, gen_moves_sentense(data->moves));
	while(i < data->map->h)
	{
		j = 0;
		while(j < data->map->w)
		{
			if(data->map->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall.image, j * 64, i * 64 + 30);
			else if(data->map->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->space.image, j * 64, i * 64 + 30);
			else if(data->map->map[i][j] == 'C'){
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collec.image, j * 64, i * 64 + 30);
			}
			else if(data->map->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit.image, j * 64, i * 64 + 30);
			else if(data->map->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->space.image, j * 64, i * 64 + 30);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player.ply_img[data->player.frame].image, j * 64, i * 64 + 30);
			}
			j++;
		}
		i++;
	}
}
