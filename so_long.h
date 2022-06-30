/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:50:29 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/29 14:34:00 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*wall;
	void	*floor;
	void	*flower;
	void	*princess;
	int		width;
	int		height;
}				t_game;

typedef struct s_data
{
	t_game	img;
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
	int		to_clct;
	int		clctd;
	int		moves;
	int		player_cnt;
	int		exits;
}				t_data;

char	**check_map(char *map_str, t_data *data);
char	**invalid_map(int code, char **str);

void	free_split(t_data *data);
void	free_map(char **map);
void	init_assets(t_game *img);
void	set_images(t_data *data);
void	go_left(t_data *data);
void	go_down(t_data *data);
void	go_right(t_data *data);
void	go_up(t_data *data);

int		error_protocol(int code, t_data *data);
int		elem_error(t_data *data);
int		quit(t_data *data);

#endif