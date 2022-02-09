/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:59:55 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/08 21:20:37 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_line_letters(char *line, int finish)
{
	static int	checked[] = {0, 0, 0};

	while(*line && !finish)
	{
		if(*line == 'P')
			checked[0] += 1 ;
		else if (*line == 'E')
			checked[1] += 1 ;
		else if (*line == 'C')
			checked[2] += 1 ;
		line++;
	}
	if(finish && (checked[0] != 1 || checked[1] == 0 || checked[2] == 0))
		return (0);
	return (1);
}

static int	check_line_letters(char *line)
{
	while(*line)
	{
		if(*line != '0' && *line != '1' && *line != 'E' && *line != 'P' && *line != 'C')
			return (0);
		line++;
	}
	return (1);
}

static int	check_map_line(char *line, int is_hor)
{
	int	len;

	if(!line || !check_line_letters(line))
		return (0);
	len = ft_strlen(line);
	if(is_hor)
	{
		while(*line)
		{
			if(*line != '1')
				return (0);
			line++;
		}
	}
	else if(line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}

int	read_map(int fd, t_data *data)
{
	int		i;
	int		initial_line_len;
	char	*tmp;
	char	*line;

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
		valid_line_letters(line, 0);
		if (i == 0)
		{
			initial_line_len = ft_strlen(line);
			if(!check_map_line(line, 1))
			{
				put_str("Error\nInvalid Map ! \n");
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
	if(!check_map_line(line, 1) || initial_line_len != ft_strlen(line) || !valid_line_letters(line, 1))
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

void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while(i < data->map->h)
	{
		j = 0;
		while(j < data->map->w )
		{
			printf("%c", data->map->map[i][j]);
			j++;
		}
		i++;
	}
}
