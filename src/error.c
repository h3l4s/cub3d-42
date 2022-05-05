/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:05:42 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 13:36:47 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

void	ft_error(char *str)
{
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	ft_error2(char *str, t_vars game)
{
	printf("%s", str);
	free_str(game.part1);
	free_str(game.temp);
	exit(EXIT_FAILURE);
}

void	ft_error3(char *str, t_ray ray)
{
	free_all(ray);
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	error_with_texture(t_ray ray, t_vars vars, int i)
{
	if (i == NORTH)
	{	
		printf("Error.\nMlx xpm for north file fail.\n");
		free_map2(&ray, vars);
	}
	if (i == SOUTH)
	{	
		printf("Error.\nMlx xpm for south file fail.\n");
		free_map2(&ray, vars);
	}
	if (i == EAST)
	{	
		printf("Error.\nMlx xpm for east file fail.\n");
		free_map2(&ray, vars);
	}
	if (i == WEST)
	{	
		printf("Error.\nMlx xpm for west file fail.\n");
		free_map2(&ray, vars);
	}
}

void	file_is_empty(char *map, char *line)
{
	if (map[0] == '\0')
	{
		free(map);
		free(line);
		printf("Error.\nFile is empty.\n");
		exit(EXIT_FAILURE);
	}
}
