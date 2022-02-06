/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:15:21 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/06 17:13:15 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_map(t_data *data)
{

	printf("YOU FINISHED 1");
	int	x;
	int	y;
	char	*joined;
	
	y = 0;
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
	joined = gen_moves_sentense(data->moves);
	put_string(data, (data->map->w * 64) / 2, (data->map->h * 64) / 2, 0, joined);
	put_string(data, (data->map->w * 64) / 2, (data->map->h * 64) / 2 + 40, 0, "PRESS ESC TO EXIT !");

	// free unused pointers !
}

char	*gen_moves_sentense(int moves)
{
	char	*score;
	char	*joined;

	score = ft_itoa(moves);
	joined = join_score("MOVES : ", score);
	free(score);
	return joined;
}

void	put_string(t_data *data, int x, int y, int color, char *s)
{
	mlx_string_put(data->mlx, data->mlx_win, x, y, color, s);
}
