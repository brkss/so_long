/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:59:55 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/14 22:34:33 by bberkass         ###   ########.fr       */
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

int	read_map(int fd)
{
	int		i;
	int		initial_line_len;
	char	*tmp;
	char	*line;

	i = 0;
	while((tmp = get_next_line(fd)))
	{
		line = tmp;
		if (i == 0)
		{
			initial_line_len = ft_strlen(line);
			if(!check_map_line(line, 1))
			{
				printf("1-Invalid Map ! \n");
				exit(1);
			}
		}
		if(!check_map_line(line, 0) || initial_line_len != ft_strlen(line))
		{
			printf("Invalid Map ! \n");
			exit(1);
		}
		i++;
	}
	printf("last line => %s \n", line);
	if(!check_map_line(line, 1))
	{
		printf("Invalid Map ! \n");
		exit(1);
	}
	return (1);
}
