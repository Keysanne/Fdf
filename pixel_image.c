/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:34:51 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/29 15:37:51 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_struc *info, int x, int y, int color)
{
	char	*dst;

	dst = info->i_addr + (y * info->ll + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}
