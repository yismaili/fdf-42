/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:31:07 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/04 19:42:36 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	fdf	*ptr;
	
	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf path/to/map.fdf", 0);
		return (0);
	}

	ptr = (fdf *)malloc(sizeof(fdf));
	ft_read_maps(argv[1], ptr);
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, W_WIDTH, W_HEIGHT, "mlx42");
	if (ptr->height < 100 && ptr->width < 100)
		ptr->zom = 10;
	else
		ptr->zom = 2;
	ptr->cos_x = 0.523599;
	ptr->sin_y = 0.523599;
	ptr->shift_x = W_WIDTH / 2;
	ptr->shift_y = W_HEIGHT / 3 - 300;
	ft_drow(ptr);
	mlx_key_hook(ptr->win_ptr, ft_key, ptr);
	mlx_loop(ptr->mlx_ptr);
}
