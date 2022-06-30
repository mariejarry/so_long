/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:14:46 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/30 11:57:07 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_assets(t_game *img)
{
		img->wall = mlx_xpm_file_to_image(img->mlx, \
				"images/wall.xpm", &img->width, &img->height);
		img->floor = mlx_xpm_file_to_image(img->mlx, \
				"images/floor.xpm", &img->width, &img->height);
		img->player = mlx_xpm_file_to_image(img->mlx, \
				"images/boyo.xpm", &img->width, &img->height);
		img->flower = mlx_xpm_file_to_image(img->mlx, \
				"images/flower.xpm", &img->width, &img->height);
		img->princess = mlx_xpm_file_to_image(img->mlx, \
				"images/chica_v2.xpm", &img->width, &img->height);
}

void	print_data(t_data *data)
{
	char	*str;

	mlx_string_put(data->img.mlx, data->img.mlx_win, 0, 0, 300, \
			"flowers picked = ");
	str = ft_itoa(data->clctd);
	mlx_string_put(data->img.mlx, data->img.mlx_win, 170, 0, 0XFF0022, str);
	free(str);
	mlx_string_put(data->img.mlx, data->img.mlx_win, 0, 20, 0, "moves = ");
	str = ft_itoa(data->moves);
	mlx_string_put(data->img.mlx, data->img.mlx_win, 80, 20, 0XFF0022, str);
	free(str);
}

void	put_image(t_data *data, void *image, int i, int j)
{
	mlx_put_image_to_window(data->img.mlx, data->img.mlx_win, \
							image, 100 * i, 100 * j);
}

void	set_images(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(data->img.mlx, data->img.mlx_win);
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->height)
		{
			if (data->map[j][i] == '1')
				put_image(data, data->img.wall, i, j);
			else
				put_image(data, data->img.floor, i, j);
			if (data->map[j][i] == 'P')
				put_image(data, data->img.player, i, j);
			else if (data->map[j][i] == 'C')
				put_image(data, data->img.flower, i, j);
			else if (data->map[j][i] == 'E')
				put_image(data, data->img.princess, i, j);
			print_data(data);
		}
	}
}
