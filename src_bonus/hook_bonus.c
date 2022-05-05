/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:09:52 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/13 13:52:26 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

int	mouse_hook(t_ray *ray)
{
	free_map(ray);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_key_press(int keycode, t_ray *ray)
{
	if (keycode == R_LEFT)
		ray->rotate_left = 1;
	else if (keycode == R_RIGHT)
		ray->rotate_right = 1;
	else if (keycode == FRONT)
		ray->front = 1;
	else if (keycode == BACK)
		ray->back = 1;
	else if (keycode == LEFT)
		ray->left = 1;
	else if (keycode == RIGHT)
		ray->right = 1;
	else if (keycode == EXIT)
		free_map(ray);
	return (1);
}

int	ft_key_release(int keycode, t_ray *ray)
{
	if (keycode == R_LEFT)
		ray->rotate_left = 0;
	else if (keycode == R_RIGHT)
		ray->rotate_right = 0;
	else if (keycode == FRONT)
		ray->front = 0;
	else if (keycode == BACK)
		ray->back = 0;
	else if (keycode == LEFT)
		ray->left = 0;
	else if (keycode == RIGHT)
		ray->right = 0;
	return (1);
}
