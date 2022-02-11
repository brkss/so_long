/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:15:21 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/11 23:18:07 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_map(t_data *data)
{
	char	*joined;

	fill_blue(data);
	joined = gen_moves_sentense(data->moves);
	put_string(data, (data->map->w * 64) / 2,
		(data->map->h * 64) / 2, joined);
	put_string(data, (data->map->w * 64) / 2,
		(data->map->h * 64) / 2 + 40, "PRESS ESC TO EXIT !");
	free(joined);
}

void	fill_blue(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->h * 64)
	{
		x = 0;
		while (x < data->map->w * 64)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, 755);
			x++;
		}
		y++;
	}
}

char	*gen_moves_sentense(int moves)
{
	char	*score;
	char	*joined;

	score = ft_itoa(moves);
	joined = join_score("MOVES : ", score);
	free(score);
	return (joined);
}

void	put_string(t_data *data, int x, int y, char *s)
{
	mlx_string_put(data->mlx, data->mlx_win, x, y, 0, s);
}
