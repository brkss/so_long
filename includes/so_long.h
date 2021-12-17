/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:36:48 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/17 03:36:49 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx.h"
#include "./get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct img_s {
	void	*image;
	int		w;
	int		h;
} t_img;

typedef struct map_s {
	char	**map;
	int	h;
	int	w;
} t_map;


typedef struct data_s {
	t_map	*map;
	int		scale;
	t_img	wall;
	t_img	space;
	t_img	collec;
	t_img	exit;
	t_img	player;
	void	*mlx;
	void	*mlx_win;	
} t_data;

int		read_map(int fd, t_data	*data);
void	fill_map(int fd, t_data *data);
void	display_map(t_data *data);
void	load_images(t_data *data);
void	set_images(t_data *data);
int 	move(int key, t_data *data);
//int	ft_strlen(char *s);

#endif
