/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:35:06 by bberkass          #+#    #+#             */
/*   Updated: 2022/01/03 22:24:02 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move(int key, t_data *data)
{
	(void)data;
	
	if(key == 13)
	{
		printf("move up \n");
		location(data, 0, -1);
		set_images(data);
	}
	else if(key == 0)
	{
		printf("move left \n");
		location(data, -1, 0);
		set_images(data);
	}
	else if(key == 2)
	{
		printf("move right \n");
		location(data, 1, 0);
		set_images(data);
	}
	else if(key == 1)
	{
		printf("move down \n");
		location(data, 0, 1);
		set_images(data);
	}

	return (1);
}

void	location(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while(i < data->map->h)
	{
		j = 0;
		while(j < data->map->w)
		{
			if(data->map->map[i][j] == 'P')
			{
				if(j + x < data->map->w && j + x > 0 && data->map->map[i + y][j + x] != '1')
				{
					data->map->map[i + y][j + x] = 'P';
					data->map->map[i][j] = '0';
					return;
				}				
			}
			j++;
		}
		i++;
	}
}


