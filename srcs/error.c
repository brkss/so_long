/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 23:46:11 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/16 00:44:32 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_error(char *line)
{
	if(line)
		free(line);
	put_str("Error\nInvalid Map ! \n");
	exit(1);
}

void	display_error_exit(char *err)
{
	put_str(err);
	exit(0);
}
