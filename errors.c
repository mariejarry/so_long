/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:55:40 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/29 15:01:30 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0 - map name
// 1 - fd == -1
// 2 - rd is too small
// 3 - wall error, invalid character

char	**invalid_map(int code, char **str)
{
	write(2, "error: ", 8);
	if (code == 0)
		write(2, "map name is invalid\n", 21);
	else if (code == 1)
		write(2, "map file not found\n", 20);
	else if (code == 2)
		write(2, "map file is too small or too large\n", 36);
	else if (code == 3)
	{
		write(2, "unexpected component(s) in map file", 36);
		write(2, " or map format is not a rectangle\n", 35);
		free_map(str);
	}
	return (NULL);
}

int	error_protocol(int code, t_data *data)
{
	if (code == 1)
	{
		write(2, "wrong number of each element in map file\n", 42);
		free_split(data);
		free(data);
	}
	return (0);
}

int	elem_error(t_data *data)
{
	if (data->to_clct < 1)
		return (0);
	if (data->player_cnt != 1)
		return (0);
	if (data->exits < 1)
		return (0);
	return (1);
}

void	free_split(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
