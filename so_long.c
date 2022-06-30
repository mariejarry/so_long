/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:50:25 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/29 14:32:41 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_elems(t_data *data)
{
	int	i;
	int	j;

	data->to_clct = 0;
	data->player_cnt = 0;
	data->exits = 0;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C')
				data->to_clct++;
			else if (data->map[i][j] == 'P')
			{
				data->player_cnt++;
				data->x = j;
				data->y = i;
			}
			else if (data->map[i][j] == 'E')
				data->exits++;
		}
	}
	return (elem_error(data));
}

int	test(int keycode, t_data *data)
{
	if (keycode == 0)
		go_left(data);
	else if (keycode == 1)
		go_down(data);
	else if (keycode == 2)
		go_right(data);
	else if (keycode == 13)
		go_up(data);
	if (keycode == 53)
		quit(data);
	return (0);
}

int	initialize_window(t_data *data)
{
	data->img.mlx = mlx_init();
	data->img.mlx_win = mlx_new_window(data->img.mlx, \
						(data->width * 100), (data->height * 100), "so_long");
	init_assets(&(data->img));
	set_images(data);
	mlx_hook(data->img.mlx_win, 17, 0, quit, data);
	mlx_key_hook(data->img.mlx_win, test, data);
	mlx_loop(data->img.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_data));
		data->moves = 0;
		data->clctd = 0;
		data->width = 0;
		data->height = 0;
		data->map = check_map(av[1], data);
		if (!data->map)
		{
			free(data);
			return (0);
		}
		if (!count_elems(data))
			return (error_protocol(1, data));
		initialize_window(data);
	}
	else
		write(2, "wrong number of arguments\n", 27);
}
