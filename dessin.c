/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:02 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/26 20:30:45 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ligne_pente(t_struc *st, t_position *p, int a, int na)
{
	int		i;
	float	x;
	float	dx;
	float	dy;
	float	pente;

	dx = p->xb - p->xa;
	dy = p->yb - p->ya;
	pente = dy / dx;
	if (pente < 0)
		pente = -pente;
	i = 0;
	while (i < dx)
	{	
		x = pente * i;
		x = floor(x);
		if (p->yb > p->ya)
			my_mlx_pixel_put(st, p->xa + i, p->ya + x, c(a, na, i));
		else if (p->yb < p->ya)
			my_mlx_pixel_put(st, p->xa + i, p->ya - x, c(a, na, i));
		else
			my_mlx_pixel_put(st, p->xa + i, p->ya, c(a, na, i));
		i++;
	}
}

void	ligne(t_struc *info, t_position *pose, int alti, int nextalti)
{
	pose->yb = pose->ya + info->e_y * alti;
	pose->yb -= info->e_y * nextalti;
	pose->xb = pose->xa - info->e_x * alti;
	pose->xb += info->e_x * nextalti + info->taille_x;
	ligne_pente(info, pose, alti, nextalti);
	pose->xa = pose->xb;
	pose->ya = pose->yb;
}

void	dessin_ligne(t_struc *info)
{
	t_position	pose;
	int			i;
	int			j;

	j = 0;
	while (j < info->y)
	{
		i = 0;
		pose.xa = 400 + info->e_x * info->map[j][i];
		pose.ya = 100 - info->e_y * info->map[j][i] + info->taille_y * j;
		while (i < info->x - 1)
		{
			ligne(info, &pose, info->map[j][i], info->map[j][i + 1]);
			i++;
		}
		j++;
	}
}

void	dessin(t_struc *info)
{
	info->taille_x = 1200 / info->x;
	info->taille_y = 800 / info->y;
	info->e_x = info->taille_x / 10;
	info->e_y = info->taille_y / 10;
	dessin_ligne(info);
	dessin_colonne(info);
}
