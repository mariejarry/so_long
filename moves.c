/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:12:43 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/29 14:20:45 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(t_data *data)
{
	free_split(data);
	mlx_destroy_window(data->img.mlx, data->img.mlx_win);
	mlx_destroy_image(data->img.mlx, data->img.floor);
	mlx_destroy_image(data->img.mlx, data->img.flower);
	mlx_destroy_image(data->img.mlx, data->img.player);
	mlx_destroy_image(data->img.mlx, data->img.princess);
	mlx_destroy_image(data->img.mlx, data->img.wall);
	free(data);
	exit(0);
}

void	go_left(t_data *data)
{
	int	i;
	int	j;

	i = data->y;
	j = data->x;
	if (data->map[i][j - 1] != '1')
	{
		if (data->map[i][j - 1] == 'E' && data->clctd == data->to_clct)
		{
			printf("you win!\n");
			quit(data);
		}
		else if (data->map[i][j - 1] == 'E')
			return ;
		if (data->map[i][j - 1] == 'C')
			data->clctd++;
		data->map[i][j] = '0';
		data->map[i][--(data->x)] = 'P';
		data->moves++;
	}
	mlx_clear_window(data->img.mlx, data->img.mlx_win);
	set_images(data);
}

void	go_right(t_data *data)
{
	int	i;
	int	j;

	i = data->y;
	j = data->x;
	if (data->map[i][j + 1] != '1')
	{
		if (data->map[i][j + 1] == 'E' && data->clctd == data->to_clct)
		{
			printf("you win!\n");
			quit(data);
		}
		else if (data->map[i][j + 1] == 'E')
			return ;
		if (data->map[i][j + 1] == 'C')
			data->clctd++;
		data->map[i][j] = '0';
		data->map[i][++(data->x)] = 'P';
		data->moves++;
	}
	mlx_clear_window(data->img.mlx, data->img.mlx_win);
	set_images(data);
}

void	go_down(t_data *data)
{
	int	i;
	int	j;

	i = data->y;
	j = data->x;
	if (data->map[i + 1][j] != '1')
	{
		if (data->map[i + 1][j] == 'E' && data->clctd == data->to_clct)
		{
			printf("you win!\n");
			quit(data);
		}
		else if (data->map[i + 1][j] == 'E')
			return ;
		if (data->map[i + 1][j] == 'C')
			data->clctd++;
		data->map[i][j] = '0';
		data->map[++(data->y)][j] = 'P';
		data->moves++;
	}
	mlx_clear_window(data->img.mlx, data->img.mlx_win);
	set_images(data);
}

void	go_up(t_data *data)
{
	int	i;
	int	j;

	i = data->y;
	j = data->x;
	if (data->map[i - 1][j] != '1')
	{
		if (data->map[i - 1][j] == 'E' && data->clctd == data->to_clct)
		{
			printf("you win!\n");
			quit(data);
		}
		else if (data->map[i - 1][j] == 'E')
			return ;
		if (data->map[i - 1][j] == 'C')
			data->clctd++;
		data->map[i][j] = '0';
		data->map[--(data->y)][j] = 'P';
		data->moves++;
	}
	mlx_clear_window(data->img.mlx, data->img.mlx_win);
	set_images(data);
}
