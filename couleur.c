/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:48:49 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/27 13:50:29 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	c(int alti, int nextalti, int i)
{
	int	x;

	x = 0xDDDDDD;
	if (alti == 10 && nextalti == 10)
		return (x + 120);
	if (alti == 0 && nextalti == 10)
		return (x + i);
	if (alti == 10 && nextalti == 0)
		return (x + 120 - i);
	if (alti == 0 && nextalti == 0)
		return (x);
	if (alti == -1 && nextalti == -1)
		return (x - 120);
	if (alti == 0 && nextalti == -1)
		return (x - i);
	if (alti == -1 && nextalti == 0)
		return (x - 120 + i);
	if (alti == -1 && nextalti == 10)
		return (x - 120 + i * 2);
	if (alti == 10 && nextalti == -1)
		return (x + 120 - i * 2);
	else
		return (x);
}
