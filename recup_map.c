/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:44:14 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/25 09:11:49 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nb_ligne(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	nb_case(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '\n' && str[i] != ' ')
			i++;
		j++;
		while (str[i] && str[i] != '\n' && str[i] == ' ')
			i++;
		if (str[i] == '\n')
			break ;
	}
	return (j);
}

int	**recup_map(char *str, t_struc *info)
{
	int		**tab;
	char	*buf;
	int		fd;
	int		ret;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		write(1, "ce fichiers n'est pas une map\n", 31);
		exit (0);
	}
	buf = malloc(10000000 + 1 * sizeof(char));
	ret = read(fd, buf, 10000000);
	buf[ret] = '\0';
	info->x = nb_case(buf);
	info->y = nb_ligne(buf);
	tab = ecrire_map(buf, info);
	free(buf);
	return (tab);
}
