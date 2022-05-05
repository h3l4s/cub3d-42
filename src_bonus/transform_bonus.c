/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:12:30 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 15:54:37 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/cub3d.h"

int	norm_transform(char *s, int i, char *type)
{
	while (s[i] == ' ' || s[i] == '\t' || s[i] == ','
		|| s[i] == '\n' || s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == type[0])
		i++;
	if (s[i] == type[1])
		i++;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == ','
		|| s[i] == '\n' || s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	return (i);
}

char	*transform(char *s, char *type)
{
	int		i;
	int		index;
	char	*ret;

	index = 0;
	ret = malloc(100);
	i = norm_transform(s, 0, type);
	if (s[i] == '.' && s[i + 1] && s[i + 1 == '/'])
	{
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != ','
			&& s[i] != '\n' && s[i] != '\r' && s[i] != '\v' && s[i] != '\f')
		{
			ret[index] = s[i];
			index++;
			i++;
		}
	}
	ret[index] = '\0';
	return (ret);
}

int	norm_transform2(char *s, int i, char *type)
{
	while (s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == type[0])
		i++;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	return (i);
}

void	free_all(t_ray ray)
{
	if (ray.north_text)
		free(ray.north_text);
	if (ray.south_text)
		free(ray.south_text);
	if (ray.west_text)
		free(ray.west_text);
	if (ray.east_text)
		free(ray.east_text);
	free_str(ray.game.part1);
	free_str(ray.game.map);
}

t_ray	transform2(char *s, char *type, t_ray ray)
{
	int	i;

	i = 1;
	while (i < 6)
		ray.stock[i++] = 0;
	ray.stock[0] = norm_transform2(s, 0, type);
	check_coma_value(s, ray);
	ray = get_rgb(s, ray);
	if (s[ray.stock[0]] || ray.rgb[0] == -1 || ray.rgb[1] == -1
		|| ray.rgb[2] == -1)
		ft_error3("Error.\nFloor or ceiling texture settings corrupted.\n", ray);
	if (ray.rgb[0] >= 0 && ray.rgb[0] <= 255 && ray.rgb[1] >= 0
		&& ray.rgb[1] <= 255
		&& ray.rgb[2] >= 0 && ray.rgb[2] <= 255)
	{
		ray.color = ray.rgb[0];
		ray.color = (ray.color << 8) + ray.rgb[1];
		ray.color = (ray.color << 8) + ray.rgb[2];
	}
	else
	{
		free_all(ray);
		ft_error("Error.\nFloor or ceiling texture not working.\n");
	}
	return (ray);
}
