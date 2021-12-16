/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:59:55 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/16 13:58:29 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_map_line(char *line, int is_hor)
{
	int	len;
	int	i;

	if(!line)
		return (0);
	len = ft_strlen(line);
	i = 0;
	if(is_hor)
	{
		while(line[i])
		{
			if(line[i] != '1' && line[i] != '\n')
				return (0);
			i++;
		}
		return (1);
	}
	if(line[0] != '1' || line[len - 2] != '1')
		return (0);
	return (1);
}

int	read_map(int fd, t_data *data)
{
	int		i;
	int		initial_line_len;
	char	*tmp;
	char	*line;

	(void)data;
	line = NULL;
	i = 0;
	tmp = NULL;
	while(tmp || i == 0)
	{
		tmp = get_next_line(fd);
		if(!tmp)
			break;
		if(line)
			free(line);
		line = tmp;
		if (i == 0)
		{
			initial_line_len = ft_strlen(line);
			if(!check_map_line(line, 1))
			{
				printf("Error\nInvalid Map ! \n");
				exit(1);
			}
		}
		if(!check_map_line(line, 0) || initial_line_len != ft_strlen(line))
		{
			printf("Error\nInvalid Map ! \n");
			exit(1);
		}
		i++;
	}
	if(!check_map_line(line, 1) || initial_line_len != ft_strlen(line))
	{
		free(line);
		printf("Error\nInvalid Map ! \n");
		exit(1);
	}
	data->map = (t_map *)malloc(sizeof(t_map));
	data->map->h = i;
	data->map->w = initial_line_len;
	free(line);
	return (1);
}
/*
void	create_matrix(int h, int w)
{
	char	*buff;

	buf = malloc(sizeof(char) * (h * w));

}
*/
void	fill_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	data->map->map = (char **)malloc(sizeof(char *) * data->map->h);
	line = get_next_line(fd);
	i = 0;
	while(line)
	{
		data->map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
}
