/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:31:58 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/16 00:43:47 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	map_checker(int fd, t_data *data)
{
	int		init_len;
	char	*tmp;
	char	*line;

	init_len = 0;
	line = NULL;
	tmp = get_next_line(fd);
	if (tmp && check_map_line(tmp, 1))
		init_len = ft_strlen(tmp);
	else
		map_error(tmp);
	while (tmp && init_len > 0)
	{
		if (line)
			free(line);
		line = tmp;
		valid_line_letters(line, 0);
		if (!check_map_line(line || init_len != ft_strlen(line)))
			map_error(line);
		tmp = get_next_line(fd);
	}
	if (!check_map_line(line, 1) || init_len != ft_strlen(line)
		|| !valid_line_letters(line, 1))
		map_error(line);
	data->map = (t_map *)malloc(sizeof(t_map));
	data->map->h = i;
	data->map->w = init_len;
	free(line); 
	return (1)
}
