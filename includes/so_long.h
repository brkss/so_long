/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:36:48 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/14 22:16:43 by bberkass         ###   ########.fr       */
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
	char	*path;
	int		w;
	int		h;
} img_t;


int	read_map(int fd);
//int	ft_strlen(char *s);

#endif
