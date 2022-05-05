/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:44 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 14:19:56 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_ray	check_ray_color2(t_ray ray)
{
	if (ray.color != -1)
		ray.ceiling_text = ray.color;
	else
		ray.ceiling_text = -1;
	return (ray);
}

t_ray	check_sides_textures(char *s, t_ray ray, int i)
{
	if (s[i] == 'N' && s[i + 1] == 'O' && !ray.north_text)
		ray.north_text = transform(s, "NO");
	if (s[i] == 'S' && s[i + 1] == 'O' && !ray.south_text)
		ray.south_text = transform(s, "SO");
	if (s[i] == 'W' && s[i + 1] == 'E' && !ray.west_text)
		ray.west_text = transform(s, "WE");
	if (s[i] == 'E' && s[i + 1] == 'A' && !ray.east_text)
		ray.east_text = transform(s, "EA");
	return (ray);
}

int	verif_long_line(char **map, int line, int i)
{
	int	space_end;

	space_end = 0;
	if ((ft_strlen(map[line - 1]) < i + 1)
		|| (ft_strlen(map[line + 1]) < i + 1))
	{
		if (map[line][i] != '1')
		{
			if (map[line][i] == 32)
			{
				space_end = i;
				while (map[line][space_end] == 32)
					space_end++;
			}
			if (map[line][space_end] != '\0' && map[line][space_end] != '1')
				return (1);
		}
	}
	return (0);
}

int	verif_when_space(char **map, int line, int i)
{
	if (map[line + 1])
	{
		if (map[line + 1][i] != 32 && map[line + 1][i] != '1')
			return (1);
	}
	return (0);
}

int	check_settings(t_ray ray)
{
	if (!ray.east_text || ray.north_text[0] == '\0')
		ray.north_text = NULL;
	if (!ray.east_text || ray.south_text[0] == '\0')
		ray.south_text = NULL;
	if (!ray.east_text || ray.east_text[0] == '\0')
		ray.east_text = NULL;
	if (!ray.east_text || ray.west_text[0] == '\0')
		ray.west_text = NULL;
	if (!ray.north_text || !ray.south_text || !ray.east_text
		|| !ray.west_text || ray.ceiling_text == -1 || ray.floor_text == -1)
		return (1);
	return (0);
}
