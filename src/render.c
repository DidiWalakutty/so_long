/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 15:58:56 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/11 22:08:12 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	place_walls(t_game *map, t_game *bag)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == '1')
			{
				if ((mlx_image_to_window(map->mlx, bag->wall, x * 32, y * 32)) \
				< 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_player(t_game *map, t_game *bag)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'P')
			{
				if ((mlx_image_to_window(map->mlx, bag->player, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_collectables(t_game *map, t_game *bag)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'C')
			{
				if ((mlx_image_to_window(map->mlx, bag->collectable, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_exit(t_game *map, t_game *bag)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'E')
			{
				if ((mlx_image_to_window(map->mlx, bag->exit, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_floor(t_game *map, t_game *bag)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == '0' || map->data[y][x] == '1' || \
			map->data[y][x] == 'C' || map->data[y][x] == 'E' || \
			map->data[y][x] == 'P')
			{
				if ((mlx_image_to_window(map->mlx, bag->floor, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
