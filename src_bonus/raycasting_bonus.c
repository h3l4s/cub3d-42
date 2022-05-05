/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:10:39 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 13:32:35 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

t_ray	pos_player(char **map, t_ray ray)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] == 'N' || map[line][i] == 'E'
				|| map[line][i] == 'S' || map[line][i] == 'W')
			{
				ray.posy = i + 0.5;
				ray.posx = line + 0.5;
				map[line][i] = '0';
				return (ray);
			}
			i++;
		}
		line++;
	}
	return (ray);
}

void	step_and_initiall_stepside(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

void	touch_wall(t_ray *ray, t_vars game)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (game.map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
	}
}

void	find_a_wall(t_ray *ray, t_vars game)
{
	touch_wall(ray, game);
	if (ray->side == 0)
		ray->perpwalldist = ((double)ray->mapx
				- ray->posx + (1 - (double)ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = ((double)ray->mapy
				- ray->posy + (1 - (double)ray->stepy) / 2) / ray->raydiry;
	ray->lineheight = (int)(1440 / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + 1440 / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + 1440 / 2;
	if (ray->drawend >= 1440)
		ray->drawend = 1440 - 1;
}

int	raycasting_bonus(t_ray *ray)
{
	ray->x = 0;
	move_with_mouse(ray);
	while (ray->x < 2560)
	{
		init_ray(ray);
		ray->camerax = 2 * ray->x / (double)2560 - 1;
		ray->raydirx = ray->dirx + ray->planex * ray->camerax;
		ray->raydiry = ray->diry + ray->planey * ray->camerax;
		ft_init_raycast(ray);
		step_and_initiall_stepside(ray);
		find_a_wall(ray, ray->game);
		texture_draw(ray, ray->game);
		ray->x++;
	}
	mlx_put_image_to_window(ray->game.mlx, ray->game.win, ray->game.img, 0, 0);
	ft_forward_back(ray);
	ft_left_right(ray);
	ft_rotate(ray);
	return (0);
}
