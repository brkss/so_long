/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:59:55 by bberkass          #+#    #+#             */
/*   Updated: 2022/03/03 00:25:17 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_line_letters(char *line, int finish)
{
	static int	checked[] = {0, 0, 0};

	while (*line && !finish)
	{
		if (*line == 'P')
			checked[0] += 1 ;
		else if (*line == 'E')
			checked[1] += 1 ;
		else if (*line == 'C')
			checked[2] += 1 ;
		line++;
	}
	if (finish && (checked[0] != 1 || checked[1] == 0 || checked[2] == 0))
		return (0);
	return (1);
}

static int	check_line_letters(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1'
			&& *line != 'E' && *line != 'P' && *line != 'C')
			return (0);
		line++;
	}
	return (1);
}

static int	check_map_line(char *line, int is_hor)
{
	int	len;

	if (!line || !check_line_letters(line))
		map_error(line);
	len = ft_strlen(line);
	if (is_hor)
	{
		while (*line)
		{
			if (*line != '1')
				map_error(line);
			line++;
		}
	}
	else if (line[0] != '1' || line[len - 1] != '1')
		map_error(line);
	return (1);
}

void	read_map(int fd, t_data *data)
{
	static int	mes[] = {0, 0};
	char		*tmp;
	char		*line;

	line = NULL;
	tmp = get_next_line(fd);
	if (tmp && check_map_line(tmp, 1))
		mes[1] = ft_strlen(tmp);
	while (tmp && mes[1] > 0 && ++mes[0])
	{
		if (line)
			free(line);
		line = tmp;
		valid_line_letters(line, 0);
		if (!check_map_line(line, 0) || mes[1] != ft_strlen(line))
			map_error(line);
		tmp = get_next_line(fd);
	}
	if (!check_map_line(line, 1) || mes[1] != ft_strlen(line)
		|| !valid_line_letters(line, 1))
		map_error(line);
	data->map = (t_map *)malloc(sizeof(t_map));
	data->map->h = mes[0];
	data->map->w = mes[1];
	free(line);
}

/*
int	read_map(int fd, t_data *data)
{
	int		i;
	int		initial_line_len;
	char	*tmp;
	char	*line;

	i = 0;
	line = NULL;
	tmp = NULL;
	while (tmp || i == 0)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (line)
			free(line);
		line = tmp;
		valid_line_letters(line, 0);
		if (i == 0)
		{
			initial_line_len = ft_strlen(line);
			if (!check_map_line(line, 1))
				map_error(NULL);
		}
		if (!check_map_line(line, 0) || initial_line_len != ft_strlen(line))
			map_error(NULL);
		i++;
	}
	if (!check_map_line(line, 1) || initial_line_len != ft_strlen(line)
		|| !valid_line_letters(line, 1))
	{
		free(line);
		map_error(NULL);
	}
	data->map = (t_map *)malloc(sizeof(t_map));
	data->map->h = i;
	data->map->w = initial_line_len;
	free(line);
	return (1);
}
*/

void	fill_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	data->map->map = (char **)malloc(sizeof(char *) * data->map->h);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		data->map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
}
