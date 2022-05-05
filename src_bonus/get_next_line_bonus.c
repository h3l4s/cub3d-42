/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:04:42 by idhiba            #+#    #+#             */
/*   Updated: 2022/01/12 22:45:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/mlx.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;
	int		e;

	e = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (e < i)
	{
		str[e] = s[e];
		e++;
	}
	str[e] = '\0';
	return (str);
}

int	read_line(int fd, char **dest)
{
	char	*buff;
	int		ret;

	ret = 0;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	if (!ft_strchr(*dest, '\n'))
		ret = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(*dest, '\n') && ret)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		*dest = ft_strjoin_free(*dest, buff, 1);
		if (*dest == NULL)
			return (-1);
		if (!ft_strchr(*dest, '\n'))
			ret = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (ret);
}

char	*ft_no_leaks(char *dest, int i)
{
	char	*tmp;

	if (dest[i] == '\n')
	{
		tmp = dest;
		dest = ft_strdup(tmp + i + 1);
		free(tmp);
	}
	else
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	static char		*dest;
	int				ret;
	int				i;

	i = 0;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (!(dest))
		dest = ft_calloc(1, 1);
	ret = read_line(fd, &dest);
	if (ret == -1)
		return (-1);
	while (dest[i] != '\n' && dest[i] != '\0')
		i++;
	*line = ft_substr(dest, 0, i);
	dest = ft_no_leaks(dest, i);
	if (!dest && !ret)
	{
		free(dest);
		return (0);
	}
	return (1);
}
