/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_temp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:26:22 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 14:32:09 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_norm	norme_split_temp(t_vars game, t_norm norm)
{
	norm.count_checked = 0;
	while (game.temp[norm.i] && norm.count_checked != 6)
	{
		game.part1[norm.i] = ft_strdup(game.temp[norm.i]);
		if ((game.part1[norm.i][0] == 'N' && game.part1[norm.i][1] == 'O')
			|| (game.part1[norm.i][0] == 'S' && game.part1[norm.i][1] == 'O')
			|| (game.part1[norm.i][0] == 'E' && game.part1[norm.i][1] == 'A')
			|| (game.part1[norm.i][0] == 'W' && game.part1[norm.i][1] == 'E')
			|| game.part1[norm.i][0] == 'F' || game.part1[norm.i][0] == 'C')
			norm.count_checked++;
		norm.i++;
	}
	return (norm);
}

t_norm	norme_split_temp2(t_vars game, t_norm norm)
{
	norm.i2 = 0;
	norm.count_checked = 0;
	while (game.temp[norm.i])
	{
		while (game.temp[norm.i][norm.count_checked] == 32
			|| game.temp[norm.i][norm.count_checked] == '\t')
			norm.count_checked++;
		if (game.temp[norm.i][norm.count_checked] != '\0')
		{
			game.map[norm.i2] = ft_strdup(game.temp[norm.i]);
			norm.i2++;
		}
		norm.count_checked = 0;
		norm.i++;
	}
	return (norm);
}

t_vars	split_temp(t_vars game)
{
	t_norm	norm;

	norm.i = 0;
	game.part1 = malloc(10000);
	norm = norme_split_temp(game, norm);
	if (!game.temp[norm.i - 1] || norm.i != 6)
	{	
		game.part1[norm.i] = NULL;
		ft_error2("Error.\nMissing or invalid texture settings.\n", game);
	}
	game.part1[norm.i] = NULL;
	if (!game.temp[norm.i])
		ft_error2("Error.\nWrong map setup.\n", game);
	game.map = malloc(10000);
	norm = norme_split_temp2(game, norm);
	game.map[norm.i2] = NULL;
	free_str(game.temp);
	return (game);
}

t_ray	init_ray_text(t_ray ray)
{
	ray.north_text = NULL;
	ray.south_text = NULL;
	ray.east_text = NULL;
	ray.west_text = NULL;
	return (ray);
}
