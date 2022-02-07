/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:10:32 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/07 21:11:30 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Things to check for 
 *	-> MAP only contains these characters : 0 1 E P C 
 *	-> MAP contains atleast : 1 exit, 1 collectible, and 1 starting position
 *	-> MAP must be rectangular 
 *	-> MAP must be closed/surrounded by walls
 */

int	str_len(char *s)
{
	int	len;

	if(!s)
		return 0;
	len = 0;
	while(s[len])
		len++;
	return (len);
}

int	check_line(char *line, int is_topend)
{
	int len;

	if(!line)
		return (0);
	len = str_len(line);
	if(!is_topend && (line[0] != '1' || line[lem - 1] != '1'))
		return (0);
	while(*line && is_topend)
	{
		if(*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	read_map(int fd, t_data *data)
{
	int		initial_len;
	int		i;
	char	*line;
	char	*tmp_line;

	initial_len = 0;
	i = 0;
	tmp_line = NULL;
	line = NULL;
	while(tmp_line)
	{
		tmp_line = get_next_line(fd);
		if(!tmp_line)
			break;
		line = tmp_line;
		if(i == 0)
		{
			initial_len = str_len(line);
			if(!check_line(line, 1))
				// invalid map;
		}
		else if(!check_line(line, 0) || str_len(line) != initial_len)
			// invalid map !
		
		i++;
	}
	if(line){
		
	}

	return 1;
}

