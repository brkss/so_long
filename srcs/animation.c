/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:44:19 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/06 22:37:26 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animate(t_data *data)
{
	if(!data->finished)
	{
		if(data->currentFrame == 60)
		{
			data->currentFrame = 0;
		}
		if(data->currentFrame % 10 == 0){
			data->player.frame += 1;	
			if(data->player.frame > 4)
				data->player.frame = 0;
		}
		data->currentFrame += 1;
		set_images(data);
	}	
	return 1;
}
