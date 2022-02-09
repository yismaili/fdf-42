/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:12:14 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/05 17:33:49 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define W_WIDTH 2000
# define W_HEIGHT 1200

typedef struct 
{
    int		width;
    int		height;
	int		**matrix;
    void	*mlx_ptr;
    void	*win_ptr;
    int		zom;
    int		color;
    int		shift_x;
    int		shift_y;
    float	cos_x;
    float	sin_y;
    int		**color_map;
    int		z;
    int		z1;
    float	x;
    float	y;
    float	x1;
    float	y1;
} fdf;

void	ft_read_maps(char *filename, fdf *data);
int	ft_key(int key, fdf *ptr);
void	ft_drow(fdf *ptr);
int	ft_atohx(char *hex);
void	ft_bresenham(fdf *ptr);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*ft_next_str(char *left_str);
char	*ft_get_line(char *left_str);
#endif
