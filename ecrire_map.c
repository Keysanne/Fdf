/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecrire_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:12:57 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/24 17:46:49 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zap_couleur(const char *nptr, int *i)
{
	if (nptr[*i] == ',' && nptr[*i + 1] == '0' && nptr[*i + 2] == 'x')
	{
		while (nptr[*i] != ' ')
		(*i)++;
	}
}

int	ft_atoi(const char *nptr, int *i)
{
	int	rst;
	int	cpt;

	cpt = 0;
	rst = 0;
	while (nptr[*i] == '\n'|| nptr[*i] == ' ')
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			cpt = 1;
		(*i)++;
	}
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		rst = rst * 10 + (nptr[*i] - '0');
		(*i)++;
	}
	if (cpt == 1)
		rst = -rst;
	zap_couleur(nptr, i);
	return (rst);
}

int	**ecrire_map(char *str, t_struc *info)
{
	int		x;
	int		y;
	int		i;
	int	**tab;

	tab = malloc((info->y + 1) * sizeof(int*));
	if (!tab)
		return (NULL);
	i = 0;
	y = 0;
	while (y <= info->y)
	{
		x = 0;
		tab[y] = malloc((info->x + 1) * sizeof(int));
		if (!tab[y])
			return (NULL);
		while (x < info->x)
		{
			tab[y][x] = ft_atoi(str, &i);
			x++;
		}
		y++;
	}
	return (tab);
}
