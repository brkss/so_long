/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:35:06 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/07 18:44:40 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move(int key, t_data *data)
{
	(void)data;


	if(key == 13)
	{
		//printf("move up \n");
		location(data, 0, -1);
	}
	else if(key == 0)
	{
		//printf("move left \n");
		location(data, -1, 0);
	}
	else if(key == 2)
	{
		//printf("move right \n");
		location(data, 1, 0);
	}
	else if(key == 1)
	{
		//printf("move down \n");
		location(data, 0, 1);
	}
	else if(key == 53) {
		mlx_destroy_window(data->mlx, data->mlx_win);
	}

	return (1);
}

void	location(t_data *data, int x, int y)
{
	int		i;
	int		j;
	int		finish;

	finish = 0;
	i = 0;
	data->moves += 1;
	printf("movement : %d \n", data->moves);
	while(i < data->map->h)
	{
		j = 0;
		while(j < data->map->w)
		{
			if(data->map->map[i][j] == 'P')
			{
				if(data->map->map[i + y][j + x] != '1')
				{
					if(data->map->map[i + y][j + x] == 'E'){
						if(data->coins_total > data->coins_count)
							data->top_exit = 1;
						else
						{
							finish = 1;
							data->finished = 1;
						}
					}
					if(data->map->map[i + y][j + x] == 'C')
						data->coins_count += 1;
					if(data->top_exit == 1 && data->map->map[i + y][j + x] != 'E')
					{
						data->top_exit = 0;
						data->map->map[i][j] = 'E';
					}
					else
						data->map->map[i][j] = '0';
					data->map->map[i + y][j + x] = 'P';
					
					if(finish)
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


