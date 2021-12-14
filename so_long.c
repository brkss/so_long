/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:22:21 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/14 03:02:31 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main()
{

	void	*mlx;
	void	*mlx_win;
	void	*image;
	img_t	img_data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "So Long !!!");
	
	img_data.path = "./d.xpm";
	img_data.w = 16;
	img_data.h = 16;
	image = mlx_xpm_file_to_image(mlx, img_data.path, &img_data.w, &img_data.h);
	if(!image)
	{
		printf("image not found !\n");
		exit(1);
	}	
	printf("w : %d \t h : %d \n", img_data.w, img_data.h);
	mlx_put_image_to_window(mlx, mlx_win, image, 16, 16);

	// game loop
	mlx_loop(mlx);
	return (0);
}
