/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:20:44 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 14:31:08 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_ray	check_ray_color(t_ray ray)
{
	if (ray.color != -1)
		ray.floor_text = ray.color;
	else
		ray.floor_text = -1;
	return (ray);
}

t_ray	choose_type(char *s, t_ray ray)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ray = check_sides_textures(s, ray, i);
		if (s[i] == 'F')
		{
			ray.color = -1;
			ray = transform2(s, "F", ray);
			ray = check_ray_color(ray);
		}
		if (s[i] == 'C')
		{
			ray.color = -1;
			ray = transform2(s, "C", ray);
			ray = check_ray_color2(ray);
		}
		i++;
	}
	return (ray);
}

t_ray	use_part1(t_ray ray)
{
	int	i;
	int	ad;

	i = 0;
	ad = 0;
	while (ray.game.part1[i])
	{
		while (ray.game.part1[i][ad])
		{
			if (ray.game.part1[i][ad] == 'N' || ray.game.part1[i][ad] == 'S'
				|| ray.game.part1[i][ad] == 'W' || ray.game.part1[i][ad] == 'E'
				|| ray.game.part1[i][ad] == 'F' || ray.game.part1[i][ad] == 'C')
			{
				ray = choose_type(ray.game.part1[i], ray);
				break ;
			}
			ad++;
		}
		ad = 0;
		i++;
	}
	return (ray);
}

void	error_start(int count, char **map)
{
	if (count > 1)
	{
		printf("Error.\nToo many spawn positions.\n");
		free_str(map);
		exit(EXIT_FAILURE);
	}
	if (count == 0)
	{
		printf("Error.\nNo spawn position found.\n");
		free_str(map);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		printf("Error.\n Too many/few arguments.");
		exit(EXIT_FAILURE);
	}
	check_extension(argv[1]);
	if (open(argv[1], O_DIRECTORY) != -1)
	{
		printf("Error.\nFile .cub is a directory.\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error.\n Couldn't open map file.\n");
		exit(EXIT_FAILURE);
	}
	parsing(fd);
	return (0);
}
