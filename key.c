/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:26:17 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/07 15:28:03 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int key, fdf *ptr)
{
	printf("%d\n", key);
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	if (key == 125)
		ptr->shift_y += 20;
	if (key == 126)
		ptr->shift_y -= 20;
	if (key == 124)
		ptr->shift_x += 20;
	if (key == 123)
		ptr->shift_x -= 20;
	if (key == 6)
		ptr->zom += 2;
	if (key == 7)
		ptr->zom -= 2;
	if (key == 87)
		ptr->cos_x += 0.2;
	if (key == 84)
		ptr->cos_x += 0.2;
	ft_drow(ptr);
	return (0);
}

int	ft_atohx(char *hex)
{
	int	length;
	int	base;
	int	decimal;

	length = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while (length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
			decimal += (hex[length] - 48) * base;
		if (hex[length] >= 'A' && hex[length] <= 'F')
			decimal += (hex[length] - 55) * base;
		if (hex[length] >= 'a' && hex[length] <= 'f')
			decimal += (hex[length] - 87) * base;
		base *= 16;
		length--;
	}
	return (decimal);
}
