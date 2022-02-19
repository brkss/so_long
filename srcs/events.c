/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:35:06 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/19 19:28:29 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move(int key, t_data *data)
{
	if (key == 13 && !data->finished)
		location(data, 0, -1);
	else if (key == 0 && !data->finished)
		location(data, -1, 0);
	else if (key == 2 && !data->finished)
		location(data, 1, 0);
	else if (key == 1 && !data->finished)
		location(data, 0, 1);
	else if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	return (1);
}

void	handle_moves(t_data *data)
{
	char	*moves;

	data->moves += 1;
	moves = gen_moves_sentense(data->moves);
	put_str(moves);
	write(1, "\n", 1);
	free(moves);
}

void	move_player(t_data *data, int i, int j, int *c)
{
	if (data->map->map[i + c[1]][j + c[0]] != '1')
	{
		handle_moves(data);
		if (data->map->map[i + c[1]][j + c[0]] == 'E')
		{
			if (data->coins_total > data->coins_count)
				data->top_exit = 1;
			else
				data->finished = 1;
		}
		if (data->map->map[i + c[1]][j + c[0]] == 'C')
			data->coins_count += 1;
		if (data->top_exit == 1 && data->map->map[i + c[1]][j + c[0]] != 'E')
		{
			data->top_exit = 0;
			data->map->map[i][j] = 'E';
		}
		else
			data->map->map[i][j] = '0';
		data->map->map[i + c[1]][j + c[0]] = 'P';
		if (data->finished)
			exit_map(data);
		else
			set_images(data);
	}
}

void	location(t_data *data, int x, int y)
{
	int		i;
	int		j;
	int		*cords;

	cords = (int *)malloc(sizeof(int) * 2);
	cords[0] = x;
	cords[1] = y;
	i = 0;
	while (i < data->map->h)
	{
		j = 0;
		while (j < data->map->w)
		{
			if (data->map->map[i][j] == 'P')
			{
				move_player(data, i, j, cords);
				free(cords);
				return ;
			}
			j++;
		}
		i++;
	}
}
