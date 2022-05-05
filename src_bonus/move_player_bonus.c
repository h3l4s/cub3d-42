/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:48:29 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/12 22:45:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

void	ft_front(t_ray *ray)
{
	if (ray->game.map[(int)(ray->posx
			+ (ray->dirx * ray->movespeed * 2))][(int)ray->posy] == '0')
		ray->posx += ray->dirx * ray->movespeed;
	if (ray->game.map[(int)(ray->posx)][(int)(ray->posy +
			(ray->diry * ray->movespeed * 2))] == '0')
		ray->posy += ray->diry * ray->movespeed;
}

void	ft_forward_back(t_ray *ray)
{
	if (ray->front == 1)
		ft_front(ray);
	if (ray->back == 1)
	{
		if (ray->game.map[(int)(ray->posx
				- (ray->dirx * ray->movespeed * 2))][(int)(ray->posy)] == '0')
			ray->posx -= ray->dirx * ray->movespeed;
		if (ray->game.map[(int)(ray->posx)][(int)(ray->posy -
					(ray->diry * ray->movespeed * 2))] == '0')
			ray->posy -= ray->diry * ray->movespeed;
	}
}

void	ft_left_right(t_ray *ray)
{
	if (ray->right == 1)
	{
		if (ray->game.map[(int)(ray->posx + ray->diry
				* (ray->movespeed * 2))][(int)ray->posy] == '0')
			ray->posx += ray->diry * ray->movespeed;
		if (ray->game.map[(int)ray->posx][(int)(ray->posy
			- ray->dirx * (ray->movespeed * 2))] == '0')
			ray->posy -= ray->dirx * ray->movespeed;
	}
	if (ray->left == 1)
	{
		if (ray->game.map[(int)(ray->posx - ray->diry
				* (ray->movespeed * 2))][(int)ray->posy] == '0')
			ray->posx -= ray->diry * ray->movespeed;
		if (ray->game.map[(int)ray->posx][(int)(ray->posy
			+ ray->dirx * (ray->movespeed * 2))] == '0')
			ray->posy += ray->dirx * ray->movespeed;
	}
}

void	ft_rotate_left(t_ray *ray, double olddirx)
{
	double	oldplanex;

	if (ray->rotate_left == 1)
	{
		olddirx = ray->dirx;
		oldplanex = ray->planex;
		ray->dirx = ray->dirx * cos(ray->rotspeed / 2)
			- ray->diry * sin(ray->rotspeed / 2);
		ray->diry = olddirx * sin(ray->rotspeed / 2)
			+ ray->diry * cos(ray->rotspeed / 2);
		ray->planex = ray->planex * cos(ray->rotspeed / 2)
			- ray->planey * sin(ray->rotspeed / 2);
		ray->planey = oldplanex * sin(ray->rotspeed / 2)
			+ ray->planey * cos(ray->rotspeed / 2);
	}
}

void	ft_rotate(t_ray *ray)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = ray->planex;
	olddirx = ray->dirx;
	if (ray->rotate_right == 1)
	{
		ray->dirx = ray->dirx * cos(-ray->rotspeed / 2)
			- ray->diry * sin(-ray->rotspeed / 2);
		ray->diry = olddirx * sin(-ray->rotspeed / 2)
			+ ray->diry * cos(-ray->rotspeed / 2);
		ray->planex = ray->planex * cos(-ray->rotspeed / 2)
			- ray->planey * sin(-ray->rotspeed / 2);
		ray->planey = oldplanx * sin(-ray->rotspeed / 2)
			+ ray->planey * cos(-ray->rotspeed / 2);
	}
	ft_rotate_left(ray, olddirx);
}
