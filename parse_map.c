/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:03:31 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/29 14:59:30 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[--len] == 'r' && str[--len] == 'e'
		&& str[--len] == 'b' && str[--len] == '.')
		return (1);
	return (0);
}

int	check_walls(char **map, t_data *data)
{
	int	i;
	int	j;

	data->width = ft_strlen(map[0]);
	data->height = 0;
	while (map[data->height])
		(data->height)++;
	i = -1;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) != data->width)
			return (1);
		if (map[i][0] != '1' || map[i][data->width - 1] != '1')
			return (1);
		j = -1;
		while (map[i][++j])
		{
			if (map[0][j] != '1' || map[data->height - 1][j] != '1')
				return (1);
		}	
	}
	return (0);
}

int	check_valid(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				return (1);
		}
	}
	return (0);
}

int	check_content(char **map, t_data *data)
{	
	int	success;

	success = 1;
	success += check_walls(map, data);
	success += check_valid(map);
	if (success == 1)
		return (1);
	return (0);
}

char	**check_map(char *map_str, t_data *data)
{
	int		fd;
	int		rd_bytes;
	char	*content;
	char	**map;

	content = NULL;
	if (!valid_name(map_str))
		return (invalid_map(0, NULL));
	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (invalid_map(1, NULL));
	content = malloc(sizeof(char) * 10000);
	rd_bytes = read(fd, content, 10000);
	close(fd);
	if (rd_bytes < 17 || rd_bytes == 10000)
	{
		free(content);
		return (invalid_map(2, NULL));
	}
	map = ft_split(content, '\n');
	free(content);
	if (!check_content(map, data))
		return (invalid_map(3, map));
	return (map);
}
