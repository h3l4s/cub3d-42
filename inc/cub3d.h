/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <idhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:11:08 by glaverdu          #+#    #+#             */
/*   Updated: 2022/01/13 15:52:49 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000
# endif

# define R_LEFT		65361
# define R_RIGHT	65363
# define EXIT		65307
# define NORTH		1
# define EAST		2
# define SOUTH		3
# define WEST		4
# define BACK		115
# define FRONT		119
# define LEFT		97
# define RIGHT		100

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <math.h>

typedef struct s_norm{
	int	i;
	int	i2;
	int	count_checked;
}				t_norm;

typedef struct s_vars{
	int		nb_move;
	char	**map;
	char	**temp;
	char	**part1;
	int		f;
	int		c;
	void	*img;
	void	*img_north;
	void	*img_south;
	void	*img_east;
	void	*img_west;
	void	*img_door;
	int		bits_per_pixel;
	int		bits_per_pixel_north;
	int		bits_per_pixel_south;
	int		bits_per_pixel_east;
	int		bits_per_pixel_west;
	int		bits_per_pixel_door;
	int		line_length;
	int		line_length_north;
	int		line_length_south;
	int		line_length_east;
	int		line_length_west;
	int		line_length_door;
	int		endian;
	int		endian_north;
	int		endian_south;
	int		endian_east;
	int		endian_west;
	int		endian_door;
	int		*img_north_addr;
	int		*img_south_addr;
	int		*img_east_addr;
	int		*img_west_addr;
	int		*img_door_addr;
	int		*addr;
	void	*mlx;
	void	*win;
	int		collectible;
	int		appears;
	int		exit;
}				t_vars;

typedef struct s_ray
{
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
	int		floor_text;
	int		ceiling_text;
	int		temp;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	int		x;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	perpwalldist;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
	int		compass;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
	int		rotate_left;
	int		rotate_right;
	int		hcount;
	int		player_dir;
	int		front;
	int		back;
	int		left;
	int		right;
	int		color;
	int		stock[6];
	int		rgb[3];
	t_vars	game;
}					t_ray;

void		ft_error3(char *str, t_ray ray);
int			mouse_hook_move(t_ray *ray);
void		launch_game_bonus(t_ray ray);
t_ray		check_ray_color2(t_ray ray);
void		move_with_mouse(t_ray *ray);
t_ray		check_sides_textures(char *s, t_ray ray, int i);
void		free_all(t_ray ray);
t_ray		get_rgb(char *s, t_ray ray);
int			ft_atoi(const char *str);
void		init_direction_vector(t_ray *ray);
int			get_next_line(int fd, char **line);
t_vars		open_window(t_vars vars, int side, t_ray ray);
char		*ft_strjoin_free(char *s1, char *s2, int f);
char		*ft_strchr(char *s, int c);
void		free_map(t_ray *ray);
void		free_text(t_ray ray);
void		*ft_calloc(int count, int size);
char		*ft_substr(char *s, int start, int len);
char		*ft_strdup(char *s);
void		file_is_empty(char *map, char *line);
int			ft_strlen(char *s);
int			ft_count(char *s1, char *s2);
int			read_line(int fd, char **dest);
char		*ft_strcat(char *dest, char *src);
char		**ft_split(char *s, char c);
int			check_settings(t_ray ray);
void		aff_perso(t_vars vars, int side);
int			check_first_and_last_line(char **map);
int			check_first_and_last_char(char **map);
void		aff_game(t_vars vars, int side);
t_ray		pos_player(char **map, t_ray ray);
int			key_hook(int keycode, t_vars *vars);
int			ft_key_press(int keycode, t_ray *ray);
int			mouse_hook(t_ray *ray);
int			ft_key_release(int keycode, t_ray *ray);
t_vars		new_map_up(t_vars vars, int count_line, int count_charac);
void		*mlx_init(void);
void		ft_error2(char *str, t_vars game);
void		aff_collect(t_vars vars, int side);
void		aff_exit(t_vars vars, int side);
t_vars		split_temp(t_vars game);
t_ray		check_orientation(char **map, t_ray ray);
int			raycasting(t_ray *ray);
int			raycasting_bonus(t_ray *ray);
int			check_settings(t_ray ray);
void		check_coma_value(char *s, t_ray ray);
void		parsing(int fd);
t_ray		ray_init(t_ray ray);
int			temp_return(char *line, int count, int temp);
void		ft_error(char *str);
int			verif_long_line(char **map, int line, int i);
t_ray		use_part1(t_ray ray);
void		error_start(int count, char **map);
int			verif_when_space(char **map, int line, int i);
void		aff_floor(t_vars vars, int side);
void		free_str(char **str);
void		launch_game(t_ray ray);
void		ft_forward_back(t_ray *ray);
void		ft_left_right(t_ray *ray);
void		ft_rotate_left(t_ray *ray, double olddirx);
void		ft_rotate(t_ray *ray);
void		ft_init_raycast(t_ray *ray);
t_ray		ft_init_texture(t_ray ray);
char		*transform(char *s, char *type);
t_ray		transform2(char *s, char *type, t_ray ray);
void		init_ray(t_ray *ray);
void		check_extension(char *str);
void		texture_draw(t_ray *ray, t_vars game);
void		free_map2(t_ray *ray, t_vars game);
void		error_with_texture(t_ray ray, t_vars vars, int i);
t_ray		init_ray_text(t_ray ray);

#endif