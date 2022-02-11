/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:23:57 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/11 23:18:53 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_images(t_data	*data)
{
	data->player.ply_img[0].image = mlx_xpm_file_to_image(
			data->mlx, "images/player/player_0.xpm",
			&data->player.ply_img[0].w, &data->player.ply_img[0].h);
	data->player.ply_img[1].image = mlx_xpm_file_to_image(
			data->mlx, "images/player/player_1.xpm",
			&data->player.ply_img[1].w, &data->player.ply_img[1].h);
	data->player.ply_img[2].image = mlx_xpm_file_to_image(
			data->mlx, "images/player/player_2.xpm",
			&data->player.ply_img[2].w, &data->player.ply_img[2].h);
	data->player.ply_img[3].image = mlx_xpm_file_to_image(
			data->mlx, "images/player/player_3.xpm",
			&data->player.ply_img[3].w, &data->player.ply_img[3].h);
	data->player.ply_img[4].image = mlx_xpm_file_to_image(
			data->mlx, "images/player/player_4.xpm",
			&data->player.ply_img[4].w, &data->player.ply_img[4].h);
}

void	load_images(t_data *data)
{
	data->wall.image = mlx_xpm_file_to_image(data->mlx,
			"images/wall.xpm", &data->wall.w, &data->wall.h);
	data->space.image = mlx_xpm_file_to_image(data->mlx,
			"images/space.xpm", &data->space.w, &data->space.h);
	data->exit.image = mlx_xpm_file_to_image(data->mlx,
			"images/exit.xpm", &data->exit.w, &data->exit.h);
	data->collec.image = mlx_xpm_file_to_image(data->mlx,
			"images/collec.xpm", &data->collec.w, &data->collec.h);
	if (!data->wall.image || !data->space.image)
	{
		printf("Error\nInvalid images !");
		exit(1);
	}
}

void	draw(t_data *data, int i, int j)
{
	int	x;
	int	y;

	y = i * 64 + 30;
	x = j * 64;
	if (data->map->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->wall.image, x, y);
	else if (data->map->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->space.image, x, y);
	else if (data->map->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->collec.image, x, y);
	else if (data->map->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->exit.image, x, y);
	else if (data->map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->space.image, x, y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player.ply_img[data->player.frame].image, x, y);
	}
}

void	set_images(t_data *data)
{
	int		i;
	int		j;
	char	*moves_sentense;

	i = 0;
	moves_sentense = gen_moves_sentense(data->moves);
	mlx_clear_window (data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, 0, 3, 255, moves_sentense);
	free(moves_sentense);
	while (i < data->map->h)
	{
		j = 0;
		while (j < data->map->w)
		{
			draw(data, i, j);
			j++;
		}
		i++;
	}
}
