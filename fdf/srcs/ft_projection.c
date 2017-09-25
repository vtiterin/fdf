/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:56:13 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:56:15 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_base_scale(t_main *tab)
{
	int d;
	int scale;

	d = sqrt(pow(tab->w, 2) + pow(tab->h, 2));
	scale = CW / d;
	if (d < 1)
		tab->scale = 1;
	else
		tab->scale = scale / 2;
}

int		ft_chcollor(t_c2d *pr1, t_c2d *pr2)
{
	if (pr1->h > pr2->h)
		return (pr1->color);
	else
		return (pr2->color);
}

t_c2d	*ft_2d_proj(t_cord *cord, t_main *tab)
{
	t_c2d	*ret;

	ret = (t_c2d*)malloc(sizeof(t_c2d));
	tab->sx = (cord->x * tab->scale);
	tab->sy = (cord->y * tab->scale);
	tab->sz = (cord->z * (tab->scale * tab->scalez));
	ft_rotate_x(tab, &tab->sx, &tab->sy, &tab->sz);
	ft_rotate_y(tab, &tab->sx, &tab->sy, &tab->sz);
	ft_rotate_z(tab, &tab->sx, &tab->sy, &tab->sz);
	if (tab->proj % 2 == 1)
	{
		ret->x2d = tab->sx * 0.5 - tab->sz * 0.5 + tab->ox;
		ret->y2d = tab->sy * 0.5 + -1 * 0.25 * tab->sz * 0.5 + tab->oy;
	}
	else
	{
		ret->x2d = tab->sx * 0.5 - tab->sy * 0.5 + tab->ox;
		ret->y2d = tab->sz * -1 + (tab->sx * 0.25 + tab->sy * 0.25) + tab->oy;
	}
	ret->color = ft_color(tab, cord->z);
	ret->h = cord->z;
	return (ret);
}
