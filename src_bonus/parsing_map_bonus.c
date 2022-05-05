/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:05:28 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 14:31:25 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

int	check_last_line(char **map, int line, int i)
{
	while (map[line][i])
	{
		if (map[line][i] != 32 && map[line][i] != '\t' && map[line][i] != '1')
			return (1);
		if (map[line][i] == 32)
		{
			if (map[line - 1][i] != 32 && map[line - 1][i] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_first_and_last_line(char **map)
{
	int	i;
	int	line;

	line = 0;
	i = 0;
	while (map[line][i])
	{
		if (map[line][i] != 32 && map[line][i] != '\t' && map[line][i] != '1')
			return (1);
		i++;
	}
	while (map[line])
		line++;
	i = 0;
	line--;
	if (check_last_line(map, line, i) == 1)
		return (1);
	return (0);
}

int	verif_around_zero(char **map, int line, int i)
{
	if (map[line][i] == '0')
	{
		if (map[line + 1][i] == 32)
			return (1);
		if (map[line - 1][i] == 32)
			return (1);
		if (map[line][i - 1] == 32)
			return (1);
		if (map[line][i + 1] == 32)
			return (1);
		if (ft_strlen(map[line - 1]) < i)
			return (1);
		if (ft_strlen(map[line + 1]) < i)
			return (1);
	}
	return (0);
}

int	norme_first_and_last_char(char **map, int line, int i)
{
	while (map[line][i])
	{
		if (verif_long_line(map, line, i) == 1)
			return (-1);
		if (verif_around_zero(map, line, i) == 1)
			return (-1);
		i++;
	}
	i--;
	return (i);
}

int	check_first_and_last_char(char **map)
{
	int	i;
	int	line;

	line = 1;
	while (map[line + 1])
	{
		i = 0;
		while (map[line][i] == 32)
		{
			if (verif_when_space(map, line, i) == 1)
				return (1);
			i++;
		}
		if (map[line][i] != '1')
			return (1);
		i = norme_first_and_last_char(map, line, i);
		if (i == -1)
			return (1);
		while (map[line][i] == 32)
			i--;
		if (map[line][i] != '1')
			return (1);
		line++;
	}
	return (0);
}
