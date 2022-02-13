/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:36:48 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/13 18:43:24 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct img_s {
	void	*image;
	int		w;
	int		h;
}	t_img;

typedef struct map_s {
	char	**map;
	int		h;
	int		w;
}	t_map;

typedef struct player_s {
	t_img	ply_img[5];
	int		x;
	int		y;
	int		frame;
}	t_player;

typedef struct data_s {
	t_map		*map;
	int			scale;
	t_img		wall;
	t_img		space;
	t_img		collec;
	t_img		exit;
	t_player	player;
	void		*mlx;
	void		*mlx_win;	

	int			coins_count;
	int			coins_total;
	int			moves;
	int			top_exit;
	int			current_frame;
	int			finished;
}	t_data;

int		read_map(int fd, t_data	*data);
void	fill_map(int fd, t_data *data);
void	display_map(t_data *data);
void	load_images(t_data *data);
void	load_player_images(t_data *data);
void	set_images(t_data *data);
int		move(int key, t_data *data);

void	location(t_data *data, int x, int y);

void	exit_map(t_data *data);
char	*ft_itoa(int n);
char	*join_score(char const *s1, char const *s2);

void	put_string(t_data *data, int x, int y, char *s);
char	*gen_moves_sentense(int moves);

int		animate(t_data *data);
void	put_str(char *s);
int		check_file_extension(char *file);

void	fill_blue(t_data *data);
void	map_error(void);
void	display_error_exit(char *err);

#endif
