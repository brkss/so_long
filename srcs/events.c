/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:35:06 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/09 19:17:42 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move(int key, t_data *data)
{
	if (key == 13)
	{
		location(data, 0, -1);
	}
	else if (key == 0)
	{
		location(data, -1, 0);
	}
	else if (key == 2)
	{
		location(data, 1, 0);
	}
	else if (key == 1)
	{
		location(data, 0, 1);
	}
	else if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	return (1);
}

void	location(t_data *data, int x, int y)
{
	int		i;
	int		j;
	char	*moves;

	i = 0;
	data->moves += 1;
	moves = gen_moves_sentense(data->moves);
	put_str(moves);
	write(1, "\n", 1);
	free(moves);
	while (i < data->map->h)
	{
		j = 0;
		while (j < data->map->w)
		{
			if (data->map->map[i][j] == 'P')
			{
				if (data->map->map[i + y][j + x] != '1')
				{
					if (data->map->map[i + y][j + x] == 'E'){
						if (data->coins_total > data->coins_count)
							data->top_exit = 1;
						else
							data->finished = 1;
					}
					if (data->map->map[i + y][j + x] == 'C')
						data->coins_count += 1;
					if (data->top_exit == 1 && data->map->map[i + y][j + x] != 'E')
					{
						data->top_exit = 0;
						data->map->map[i][j] = 'E';
					}
					else
						data->map->map[i][j] = '0';
					data->map->map[i + y][j + x] = 'P';
					
					if (data->finished)
						exit_map(data);
					else
						set_images(data);
					return;
				}				
			}
			j++;
		}
		i++;
	}
}
