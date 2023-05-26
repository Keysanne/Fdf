/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:27:16 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/26 11:28:40 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	clear_leaks(t_struc *info)
{
	int	i;

	i = 0;
	while (i <= info->y)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	mlx_destroy_window(info->connexion, info->window);
	mlx_destroy_display(info->connexion);
	free(info->connexion);
}

int	key_event(int x, t_struc *info)
{
	if (x == 65307)
	{
		clear_leaks(info);
		exit (0);
	}
	return (0);
}

int	close_button(t_struc *info)
{
	clear_leaks(info);
	exit (0);
}

void	window(t_struc *info)
{
	info->connexion = mlx_init();
	info->window = mlx_new_window(info->connexion, 1920, 995, "Fdf");
	dessin(info);
	mlx_key_hook(info->window, key_event, info);
	mlx_hook(info->window, 17, 1L << 1, close_button, info);
	mlx_loop(info->connexion);
}

int	main(int argc, char **argv)
{
	t_struc info;
	int	fd;

	if (argc == 2)
	{
		info.map = recup_map(argv[1], &info);
		window(&info);
	}
	else
		write(1, "la fonction a besoin d'un unique argument\n", 42);
	return (0);
}
