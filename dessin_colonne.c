/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin_colonne.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:31:17 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/26 20:32:22 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	colonne_pente(t_struc *st, t_position *p, int a, int na)
{
	int		i;
	float	x;
	float	dx;
	float	dy;
	float	pente;

	dx = p->xb - p->xa;
	dy = p->yb - p->ya;
	pente = dx / dy;
	if (pente < 0)
		pente = -pente;
	i = 0;
	while (i < dy)
	{
		x = pente * i;
		x = floor(x);
		if (p->xb > p->xa)
			my_mlx_pixel_put(st, p->xa + x, p->ya + i, c(a, na, i));
		else if (p->xb < p->xa)
			my_mlx_pixel_put(st, p->xa - x, p->ya + i, c(a, na, i));
		else
			my_mlx_pixel_put(st, p->xa, p->ya + i, c(a, na, i));
		i++;
	}
}

void	colonne(t_struc *info, t_position *pose, int alti, int nextalti)
{
	pose->yb = pose->ya + info->e_y * alti + info->taille_y;
	pose->yb -= info->e_y * nextalti;
	pose->xb = pose->xa - info->e_x * alti;
	pose->xb += info->e_x * nextalti;
	colonne_pente(info, pose, alti, nextalti);
	pose->xa = pose->xb;
	pose->ya = pose->yb;
}

void	dessin_colonne(t_struc *info)
{
	t_position	pose;
	int			i;
	int			j;

	i = 0;
	while (i < info->x)
	{
		j = 0;
		pose.xa = 400 + info->e_x * info->map[j][i] + info->taille_x * i;
		pose.ya = 100 - info->e_y * info->map[j][i];
		while (j < info->y - 1)
		{
			colonne(info, &pose, info->map[j][i], info->map[j + 1][i]);
			j++;
		}
		i++;
	}
}
