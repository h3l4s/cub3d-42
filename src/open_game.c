/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:06:19 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 13:40:11 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_vars	load_image(int s, t_vars vars, t_ray ray)
{
	vars.img_north = mlx_xpm_file_to_image(vars.mlx, ray.north_text, &s, &s);
	if (!vars.img_north)
		error_with_texture(ray, vars, NORTH);
	vars.img_north_addr = (int *)mlx_get_data_addr(vars.img_north,
			&vars.bits_per_pixel_north,
			&vars.line_length_north, &vars.endian_north);
	vars.img_south = mlx_xpm_file_to_image(vars.mlx, ray.south_text, &s, &s);
	if (!vars.img_south)
		error_with_texture(ray, vars, SOUTH);
	vars.img_south_addr = (int *)mlx_get_data_addr(vars.img_south,
			&vars.bits_per_pixel_south,
			&vars.line_length_south, &vars.endian_south);
	vars.img_east = mlx_xpm_file_to_image(vars.mlx, ray.east_text, &s, &s);
	if (!vars.img_east)
		error_with_texture(ray, vars, EAST);
	vars.img_east_addr = (int *)mlx_get_data_addr(vars.img_east,
			&vars.bits_per_pixel_east,
			&vars.line_length_east, &vars.endian_east);
	vars.img_west = mlx_xpm_file_to_image(vars.mlx, ray.west_text, &s, &s);
	if (!vars.img_west)
		error_with_texture(ray, vars, WEST);
	vars.img_west_addr = (int *)mlx_get_data_addr(vars.img_west,
			&vars.bits_per_pixel_west,
			&vars.line_length_west, &vars.endian_west);
	return (vars);
}

t_vars	open_window(t_vars vars, int side, t_ray ray)
{
	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_error("Error.\nMlx init fail.\n");
	vars = load_image(64, vars, ray);
	side++;
	vars.win = mlx_new_window(vars.mlx, 2560, 1440, "cub3d");
	if (!vars.win)
		ft_error("Error.\nMlx new window fail.\n");
	return (vars);
}

void	launch_game(t_ray ray)
{
	ray.game = open_window(ray.game, 64, ray);
	ray.game.img = mlx_new_image(ray.game.mlx, 2560, 1440);
	ray.game.addr = (int *)mlx_get_data_addr(ray.game.img,
			&ray.game.bits_per_pixel, &ray.game.line_length, &ray.game.endian);
	mlx_hook(ray.game.win, 2, 1L << 0, ft_key_press, &ray);
	mlx_loop_hook(ray.game.mlx, raycasting, &ray);
	mlx_hook(ray.game.win, 3, 1L << 1, ft_key_release, &ray);
	mlx_hook(ray.game.win, 17, 1L << 17, mouse_hook, &ray);
	mlx_loop(ray.game.mlx);
}
