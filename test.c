/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:27:16 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/19 16:10:09 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main()
{
	void	*ptr;
	void	*windows;
	int	x;
	int	y;

	x = 0;
	y = 0;
	ptr = mlx_init();
	windows = mlx_new_window(ptr, 1920, 995, "test");
	while (x < 1920 || y < 995)
	{
		mlx_pixel_put(ptr, windows, x, 0, 0xFFFFFF);
		mlx_pixel_put(ptr, windows, x, 995/2, 0xFFFFFF);
		mlx_pixel_put(ptr, windows, x, 994, 0xFFFFFF);
		mlx_pixel_put(ptr, windows, 0, y, 0xFFFFFF);
		mlx_pixel_put(ptr, windows, 1920/2, y, 0xFFFFFF);
		mlx_pixel_put(ptr, windows, 1919, y, 0xFFFFFF);
		x++;
		y++;
	}
	mlx_loop(ptr);
}
