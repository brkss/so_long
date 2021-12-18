/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:35:06 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/17 20:20:54 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move(int key, t_data *data)
{
	(void)data;
	
	if(key == 13)
	{
		printf("move up \n");
	}
	else if(key == 0)
	{
		printf("move left \n");
	}
	else if(key == 1)
	{
		printf("move right \n");
	}
	else if(key == 2)
	{
		printf("move down \n");
	}

	return (1);
}
