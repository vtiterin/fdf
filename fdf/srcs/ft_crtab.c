/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:58:16 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:58:18 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_chm(char *arvg, int *h, int *w)
{
	char	*str;
	int		wr;

	wr = 0;
	str = read_matrix(arvg, h, w);
	wr = ft_words(str, ' ');
	if (wr == 0)
	{
		ft_putstr("Empty file. Exiting.\n");
		exit(1);
	}
	else if (wr != *h * *w)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		exit(1);
	}
	return (str);
}

t_cord	***cord_tab(char *arvg, int *w, int *h, int *maxz)
{
	t_cord	***tab;
	char	**cord;
	int		i;
	int		y;
	int		c;

	cord = ft_strsplit(ft_chm(arvg, h, w), ' ');
	tab = (t_cord***)malloc(sizeof(t_cord**) * (*h));
	i = -1;
	c = 0;
	while (++i < *h)
	{
		tab[i] = (t_cord**)malloc(sizeof(t_cord*) * (*w));
		y = -1;
		while (++y < *w)
		{
			tab[i][y] = (t_cord*)malloc(sizeof(t_cord));
			tab[i][y]->x = y - (*w / 2);
			tab[i][y]->y = i - (*h / 2);
			tab[i][y]->z = ft_atoi(cord[c++]);
			*maxz < tab[i][y]->z ? *maxz = tab[i][y]->z : 0;
		}
	}
	ft_frtab(cord);
	return (tab);
}
