/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mous_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:52:24 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 13:34:23 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

void	move_with_mouse(t_ray *ray)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(ray->game.mlx, ray->game.win, &x, &y);
	if (x < 1100)
		ray->rotate_left = 1;
	else
		ray->rotate_left = 0;
	if (x > 1460)
		ray->rotate_right = 1;
	else
		ray->rotate_right = 0;
}
