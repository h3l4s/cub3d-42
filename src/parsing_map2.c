/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:07:54 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 15:45:10 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

void	verif_one_start_position(char **map)
{
	int	i;
	int	line;
	int	count;

	line = 0;
	count = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] == 'W' || map[line][i] == 'E'
				|| map[line][i] == 'N' || map[line][i] == 'S')
				count++;
			i++;
		}
		line++;
	}
	error_start(count, map);
}

void	verif_inside_char(char **map, t_ray ray)
{
	int	i;
	int	line;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] != ' ' && map[line][i] != '1'
			&& map[line][i] != '0' && map[line][i] != 'W'
			&& map[line][i] != 'E' && map[line][i] != 'N'
			&& map[line][i] != 'S')
			{
				printf("Error.\nWrong char in map.\n");
				free_all(ray);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		line++;
	}
	verif_one_start_position(map);
}

void	ft_verif_parsing(t_ray ray)
{
	if (check_settings(ray))
	{
		printf("Error.\nWrong texture/color settings.\n");
		free_str(ray.game.map);
		free_str(ray.game.part1);
		free_text(ray);
		exit(EXIT_FAILURE);
	}
	if ((check_first_and_last_line(ray.game.map) == 1))
	{
		free_str(ray.game.map);
		free_str(ray.game.part1);
		free_text(ray);
		printf("Error.\nInvalid map.\n");
		exit(EXIT_FAILURE);
	}
	if ((check_first_and_last_char(ray.game.map) == 1))
	{
		free_str(ray.game.map);
		free_str(ray.game.part1);
		free_text(ray);
		printf("Error.\nInvalid map.\n");
		exit(EXIT_FAILURE);
	}
}

char	*recup_the_file(int fd, char *map)
{
	int		count;
	char	*line;
	int		temp;

	count = 0;
	temp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
			count++;
		temp = temp_return(line, count, temp);
		map = ft_strcat(map, line);
		free(line);
	}
	if (temp == 3)
	{
		free(line);
		free(map);
		printf("Error.\nInvalid data in .cub file.\n");
		exit(EXIT_FAILURE);
	}
	file_is_empty(map, line);
	map = ft_strcat(map, line);
	free(line);
	return (map);
}

void	parsing(int fd)
{
	char	*map;
	t_ray	ray;

	map = ft_strdup("");
	ray.ceiling_text = -1;
	ray.floor_text = -1;
	map = recup_the_file(fd, map);
	ray = init_ray_text(ray);
	ray.game.temp = ft_split(map, '|');
	free(map);
	ray.game = split_temp(ray.game);
	ray = use_part1(ray);
	ft_verif_parsing(ray);
	verif_inside_char(ray.game.map, ray);
	ray = check_orientation(ray.game.map, ray);
	ray = ray_init(ray);
	launch_game(ray);
}
