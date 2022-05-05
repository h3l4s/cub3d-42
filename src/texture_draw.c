/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:02:35 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/12 22:45:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

void	display_texture(t_ray *ray, int y, int x)
{
	if (ray->compass == 0)
		ray->game.addr[y * ray->game.line_length / 4 + x]
			= ray->game.img_north_addr[ray->texy
			* ray->game.line_length_north / 4 + ray->texx];
	else if (ray->compass == 1)
		ray->game.addr[y * ray->game.line_length / 4 + x]
			= ray->game.img_south_addr[ray->texy
			* ray->game.line_length_south / 4 + ray->texx];
	else if (ray->compass == 2)
		ray->game.addr[y * ray->game.line_length / 4 + x]
			= ray->game.img_east_addr[ray->texy
			* ray->game.line_length_east / 4 + ray->texx];
	else if (ray->compass == 3)
		ray->game.addr[y * ray->game.line_length / 4 + x]
			= ray->game.img_west_addr[ray->texy
			* ray->game.line_length_west / 4 + ray->texx];
}

void	ft_draw_texture(t_ray *ray, int x, int y)
{
	y = ray->drawstart - 1;
	*ray = ft_init_texture(*ray);
	while (++y <= ray->drawend)
	{
		ray->texy = (int)ray->texpos & (64 - 1);
		ray->texpos += ray->step;
		if (y < 1440 && x < 2560)
			display_texture(ray, y, x);
	}
}

void	texture_draw(t_ray *ray, t_vars game)
{
	int	j;
	int	i;

	j = -1;
	ray->drawend = 1440 - ray->drawstart;
	i = ray->drawend;
	while (++j < ray->drawstart)
		game.addr[j * game.line_length / 4
			+ ray->x] = ray->ceiling_text;
	if (j <= ray->drawend)
		ft_draw_texture(ray, ray->x, j);
	j = i;
	while (++j < 1440)
		game.addr[j * game.line_length / 4
			+ ray->x] = ray->floor_text;
}
