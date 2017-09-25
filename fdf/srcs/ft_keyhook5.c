/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:47:20 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:47:22 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color_b0(t_main *tab)
{
	tab->col->p0 += 1;
	ft_col0(tab, tab->col->p0);
	expose_hook(tab);
}

void	ft_color_b1(t_main *tab)
{
	tab->col->p1 += 1;
	ft_col1(tab, tab->col->p1);
	expose_hook(tab);
}

void	ft_color_b2(t_main *tab)
{
	tab->col->p2 += 1;
	ft_col2(tab, tab->col->p2);
	expose_hook(tab);
}

void	ft_color_b3(t_main *tab)
{
	tab->col->p3 += 1;
	ft_col3(tab, tab->col->p3);
	expose_hook(tab);
}

void	ft_zoom_up(t_main *tab)
{
	if (sqrt(pow(tab->w * tab->scale, 2) +
		pow(tab->h * tab->scale, 2)) < CW)
		tab->scale = tab->scale + 1;
	expose_hook(tab);
}
