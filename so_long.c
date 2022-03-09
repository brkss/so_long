/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:22:21 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/13 18:20:31 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_data(t_data *data)
{
	data->scale = 64;
	data->coins_count = 0;
	data->coins_total = 0;
	data->moves = 0;
	data->top_exit = 0;
	data->current_frame = 0;
	data->player.frame = 1;
	data->finished = 0;
}

int	count_coins(t_map *map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	load(t_data *data, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	fill_map(fd, data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map->w * 64, data->map->h * 64, "sl");
	data->coins_total = count_coins(data->map);
	load_images(data);
	load_player_images(data);
	set_images(data);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (argc >= 2)
	{
		if (!check_file_extension(argv[1]))
			display_error_exit("Error\nInvalid File !\n");
		fd = open(argv[1], O_RDONLY);
		if (fd < 3)
			display_error_exit("Error\ninvalid file ! \n");
		data = (t_data *)malloc(sizeof(t_data));
		init_data(data);
		read_map(fd, data);
		load(data, argv[1]);
		mlx_loop_hook(data->mlx, animate, data);
		mlx_key_hook(data->mlx_win, move, data);
		mlx_hook(data->mlx_win, 17, 0, move, data);
		mlx_loop(data->mlx);
	}
	else
		display_error_exit("Error\nMissing Map ! \n");
	system("leaks so_long");
	return (0);
}
