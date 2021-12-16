/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:22:21 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/16 13:58:57 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if(argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if(fd < 3)
		{
			printf("Error\ninvalid file ! \n");
			exit(0);
		}	
		data = (t_data	*)malloc(sizeof(t_data));
		read_map(fd, data);
		fd = open(argv[1], O_RDONLY);
		if(data->map)
		{
			printf("map h => %d \n", data->map->h);
			printf("map w => %d \n", data->map->w);
		}
		fill_map(fd, data);
	}
	else
	{
		printf("Error\nMissing Map ! \n");
		exit(0);
	}
	system("leaks so_long");
	return (0);
}

/*
int main()
{

	void	*mlx;
	void	*mlx_win;
	void	*image;
	img_t	img_data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "So Long !!!");
	
	img_data.path = "./d.xpm";
	img_data.w = 16 * 2;
	img_data.h = 16 * 2;
	image = mlx_xpm_file_to_image(mlx, img_data.path, &img_data.w, &img_data.h);
	if(!image)
	{
		printf("image not found !\n");
		exit(1);
	}	
	printf("w : %d \t h : %d \n", img_data.w, img_data.h);
	
	int x = 0;
	int y = 0;
	while(y < 600)
	{
		x = 0;
		while(x < 600)
		{
			mlx_put_image_to_window(mlx, mlx_win, image, x, y);
			x += 16;
		}
		y += 16;
	}
	mlx_put_image_to_window(mlx, mlx_win, image, 16, 16);

	// game loop
	mlx_loop(mlx);
	return (0);
}*/
