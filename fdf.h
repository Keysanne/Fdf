/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:37:14 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/25 09:21:42 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_struc
{
	void	*c;
	void	*w;
	int	x;
	int	y;
	int	taille_x;
	int	taille_y;
	int	e_x;
	int	e_y;
	int	**map;
}		t_struc;

typedef struct	s_position
{
	int	xa;
	int	ya;
	int	xb;
	int	yb;
	float	pente;
}		t_position;

void	window(t_struc *info);
int	**recup_map(char *str, t_struc *info);
int	**ecrire_map(char *str, t_struc *info);
int	couleur(int alti, int nextalti, int i);
void	dessin(t_struc *info);
void	dessin_colonne(t_struc *info);

#endif
