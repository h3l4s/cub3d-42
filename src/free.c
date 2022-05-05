/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:18:09 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 15:44:51 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

void	free_str(char **str)
{
	int	line;

	line = 0;
	while (str[line])
	{
		free(str[line]);
		line++;
	}
	free(str);
}

void	free_map(t_ray *ray)
{
	free_str(ray->game.map);
	if (ray->game.img_north)
		mlx_destroy_image(ray->game.mlx, ray->game.img_north);
	if (ray->game.img_south)
		mlx_destroy_image(ray->game.mlx, ray->game.img_south);
	if (ray->game.img_east)
		mlx_destroy_image(ray->game.mlx, ray->game.img_east);
	if (ray->game.img_west)
		mlx_destroy_image(ray->game.mlx, ray->game.img_west);
	if (ray->game.img)
		mlx_destroy_image(ray->game.mlx, ray->game.img);
	if (ray->game.win)
		mlx_destroy_window(ray->game.mlx, ray->game.win);
	if (ray->game.mlx)
		mlx_destroy_display(ray->game.mlx);
	if (ray->game.mlx)
		free(ray->game.mlx);
	free_str(ray->game.part1);
	free(ray->north_text);
	free(ray->east_text);
	free(ray->west_text);
	free(ray->south_text);
	exit(EXIT_SUCCESS);
}

void	free_map2(t_ray *ray, t_vars game)
{
	free_str(game.map);
	if (game.img_north)
		mlx_destroy_image(game.mlx, game.img_north);
	if (game.img_south)
		mlx_destroy_image(game.mlx, game.img_south);
	if (game.img_east)
		mlx_destroy_image(game.mlx, game.img_east);
	if (game.img_west)
		mlx_destroy_image(game.mlx, game.img_west);
	if (game.img)
		mlx_destroy_image(game.mlx, game.img);
	if (game.win)
		mlx_destroy_window(game.mlx, game.win);
	if (game.mlx)
		mlx_destroy_display(game.mlx);
	if (game.mlx)
		free(game.mlx);
	free_str(game.part1);
	free(ray->north_text);
	free(ray->east_text);
	free(ray->west_text);
	free(ray->south_text);
	exit(EXIT_SUCCESS);
}

void	free_text(t_ray ray)
{
	if (ray.north_text)
		free(ray.north_text);
	if (ray.south_text)
		free(ray.south_text);
	if (ray.east_text)
		free(ray.east_text);
	if (ray.west_text)
		free(ray.west_text);
}

int	temp_return(char *line, int count, int temp)
{
	if (line[0] != '\0' && count >= 6 && temp != 2 && temp != 3)
		temp = 1;
	if (line[0] == '\0' && temp == 1 && count > 6)
		temp = 2;
	if (line[0] == '\0' && temp == 2 && count > 6)
		temp = 3;
	return (temp);
}
