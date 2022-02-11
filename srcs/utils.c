/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:09:46 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/11 23:21:23 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	check_file_extension(char *file)
{
	int	len;
	int	i;

	if (!file)
		return (0);
	len = ft_strlen(file);
	i = len - 1;
	while (i > 0)
	{
		if (file[i] == '.' && i + 3 == len - 1)
		{
			if (file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r' )
				return (1);
			return (0);
		}
		i--;
	}
	return (0);
}
