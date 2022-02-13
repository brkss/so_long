/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:44:19 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/11 23:23:52 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animate(t_data *data)
{
	if (!data->finished)
	{
		if (data->current_frame == 60)
		{
			data->current_frame = 0;
		}
		if (data->current_frame % 10 == 0)
		{
			data->player.frame += 1;
			if (data->player.frame > 4)
				data->player.frame = 0;
		}
		data->current_frame += 1;
		set_images(data);
	}	
	return (1);
}
