/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:58:50 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 15:55:16 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_ray	check_orientation_norme(t_ray ray, char **map, int line, int i)
{
	if (map[line][i] == 'N')
		ray.player_dir = NORTH;
	else if (map[line][i] == 'E')
		ray.player_dir = EAST;
	else if (map[line][i] == 'S')
		ray.player_dir = SOUTH;
	else if (map[line][i] == 'W')
		ray.player_dir = WEST;
	return (ray);
}

t_ray	check_orientation(char **map, t_ray ray)
{
	int	i;
	int	line;

	line = 0;
	i = 0;
	ray.player_dir = 0;
	while (map[line] != NULL)
	{
		while (map[line][i])
		{
			ray = check_orientation_norme(ray, map, line, i);
			if (ray.player_dir)
				return (ray);
			i++;
		}
		i = 0;
		line++;
	}
	return (ray);
}

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if ((str[i] != 'b') || (str[i - 1] != 'u') || (str[i - 2] != 'c')
		|| (str[i - 3] != '.'))
	{
		printf("Error.\nNo .cub file found.\n");
		exit(EXIT_FAILURE);
	}
}

void	verif_the_coma(char *s, t_ray ray)
{
	int	i;

	i = ray.stock[0];
	if (s[i] == ',')
	{
		i++;
		while (s[i] == 32)
			i++;
		if (s[i] == ',' || s[i] == '\0')
		{	
			free_all(ray);
			printf("Error.\nCeiling/floor colors corrupted.\n");
			exit(1);
		}
	}
}

t_ray	get_rgb(char *s, t_ray ray)
{
	ray.rgb[0] = -1;
	ray.rgb[1] = -1;
	ray.rgb[2] = -1;
	while ((s[ray.stock[0]] >= '0' && s[ray.stock[0]] <= '9')
		|| (s[ray.stock[0]] == ',' || s[ray.stock[0]] == 32))
	{
		verif_the_coma(s, ray);
		if (s[ray.stock[0]] != ',' && s[ray.stock[0]] != 32)
		{
			ray.stock[3] = (ray.stock[3] * 10) + s[ray.stock[0]] - 48;
			ray.stock[4] = (ray.stock[4] * 10) + (s[ray.stock[0]] - 48);
			ray.stock[5]++;
		}
		ray.stock[0]++;
		if (ray.stock[5] <= 3 && ((s[ray.stock[0]] < '0'
					|| s[ray.stock[0]] > '9') && s[ray.stock[0]] != 32))
		{
			ray.rgb[ray.stock[1]] = ray.stock[3];
			ray.stock[3] = 0;
			ray.stock[5] = 0;
			ray.stock[1]++;
		}
	}
	return (ray);
}
