/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:36:38 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/12 22:45:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_ray	ray_init(t_ray ray)
{
	ray.rotate_right = 0;
	ray.rotate_left = 0;
	ray.hcount = 0;
	ray.dirx = 0;
	ray.diry = 0;
	ray.planex = 0;
	ray.planey = 0;
	ray.game.img_west = NULL;
	ray.game.img_north = NULL;
	ray.game.img_south = NULL;
	ray.game.img_east = NULL;
	ray.game.img = NULL;
	ray.game.win = NULL;
	ray.game.mlx = NULL;
	ray.left = 0;
	ray.right = 0;
	ray.front = 0;
	ray = pos_player(ray.game.map, ray);
	ray.back = 0;
	init_direction_vector(&ray);
	return (ray);
}

void	ft_init_raycast(t_ray *ray)
{
	if (ray->raydiry == 0)
		ray->deltadistx = 0;
	else if (ray->raydirx == 0)
		ray->deltadistx = 1;
	else
		ray->deltadistx = sqrt(1 + (ray->raydiry
					* ray->raydiry) / (ray->raydirx
					* ray->raydirx));
	if (ray->raydirx == 0)
		ray->deltadisty = 0;
	else if (ray->raydiry == 0)
		ray->deltadisty = 1;
	else
		ray->deltadisty = sqrt(1 + (ray->raydirx
					* ray->raydirx) / (ray->raydiry
					* ray->raydiry));
}

t_ray	ft_init_texture(t_ray ray)
{
	if (ray.side == 0 && ray.raydirx < 0)
		ray.compass = 0;
	else if (ray.side == 0 && ray.raydirx >= 0)
		ray.compass = 1;
	else if (ray.side == 1 && ray.raydiry < 0)
		ray.compass = 2;
	else if (ray.side == 1 && ray.raydiry >= 0)
		ray.compass = 3;
	if (ray.side == 0)
		ray.wallx = ray.posy + ray.perpwalldist
			* ray.raydiry;
	else
		ray.wallx = ray.posx + ray.perpwalldist
			* ray.raydirx;
	ray.wallx -= floor((ray.wallx));
	ray.texx = (int)(ray.wallx * (double)64);
	if (ray.side == 0 && ray.raydirx > 0)
		ray.texx = 64 - ray.texx - 1;
	if (ray.side == 1 && ray.raydiry < 0)
		ray.texx = 64 - ray.texx - 1;
	ray.step = 1.0 * 64 / ray.lineheight;
	ray.texpos = (ray.drawstart - 1440 / 2 + ray.lineheight / 2) * ray.step;
	return (ray);
}

void	init_direction_vector(t_ray *ray)
{
	if (ray->player_dir == NORTH)
		ray->dirx = -1;
	if (ray->player_dir == SOUTH)
		ray->dirx = 1;
	if (ray->player_dir == EAST)
		ray->diry = 1;
	if (ray->player_dir == WEST)
		ray->diry = -1;
	if (ray->player_dir == NORTH)
		ray->planey = 0.66;
	if (ray->player_dir == SOUTH)
		ray->planey = -0.66;
	if (ray->player_dir == EAST)
		ray->planex = 0.66;
	if (ray->player_dir == WEST)
		ray->planex = -0.66;
}

void	init_ray(t_ray *ray)
{
	ray->perpwalldist = 0;
	ray->hit = 0;
	ray->mapx = (int)ray->posx ;
	ray->mapy = (int)ray->posy ;
	ray->movespeed = 0.2;
	ray->rotspeed = 0.05 * 1.8;
}
