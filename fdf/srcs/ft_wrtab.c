/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:57:25 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:57:27 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_inibres(t_bresenh *br, t_c2d *pr1, t_c2d *pr2)
{
	br->deltax = ABS(pr2->x2d - pr1->x2d);
	br->deltay = ABS(pr2->y2d - pr1->y2d);
	br->signx = pr1->x2d < pr2->x2d ? 1 : -1;
	br->signy = pr1->y2d < pr2->y2d ? 1 : -1;
	br->err = br->deltax - br->deltay;
}

void	ft_drawline(t_c2d *pr1, t_c2d *pr2, char *data, int size)
{
	t_bresenh	*br;
	int			c;

	br = (t_bresenh*)malloc(sizeof(t_bresenh));
	ft_inibres(br, pr1, pr2);
	c = ft_chcollor(pr1, pr2);
	while (pr1->x2d != pr2->x2d || pr1->y2d != pr2->y2d)
	{
		if (((pr1->x2d) * 4) + ((pr1->y2d) * size) < (size * CH)
			&& ((pr1->x2d) * 4) + ((pr1->y2d) * size) > 0)
			ft_memcpy(&data[((pr1->x2d) * 4) + ((pr1->y2d) * size)],
			&(c), 4);
		br->err2 = br->err * 2;
		if (br->err2 > -(br->deltay))
		{
			br->err -= br->deltay;
			pr1->x2d += br->signx;
		}
		if (br->err2 < br->deltax)
		{
			br->err += br->deltax;
			pr1->y2d += br->signy;
		}
	}
}

void	ft_wrtab_hor(t_main *tab, int y, int i)
{
	t_c2d	*p1;
	t_c2d	*p2;

	p1 = ft_2d_proj(tab->tab[i][y], tab);
	p2 = ft_2d_proj(tab->tab[i][y + 1], tab);
	ft_drawline(p1, p2, tab->ibuf, tab->isize);
	free(p1);
	free(p2);
}

void	ft_wrtab_vert(t_main *tab, int y, int i)
{
	t_c2d	*p1;
	t_c2d	*p3;

	p1 = ft_2d_proj(tab->tab[i][y], tab);
	p3 = ft_2d_proj(tab->tab[i + 1][y], tab);
	ft_drawline(p1, p3, tab->ibuf, tab->isize);
	free(p1);
	free(p3);
}

void	ft_wr_tab(t_main *tab)
{
	int		i;
	int		y;

	i = 0;
	while (i < tab->h)
	{
		y = 0;
		while (y < tab->w)
		{
			if (y + 1 < tab->w)
				ft_wrtab_hor(tab, y, i);
			if (i + 1 < tab->h)
				ft_wrtab_vert(tab, y, i);
			y++;
		}
		i++;
	}
}
