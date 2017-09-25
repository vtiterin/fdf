/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:53:18 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:53:20 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_main *tab, int *sx, int *sy, int *sz)
{
	int zx;
	int zy;
	int zz;

	zx = *sx;
	zy = *sy;
	zz = *sz;
	*sx = zx;
	*sy = zy * cos(tab->anglex) - zz * sin(tab->anglex);
	*sz = zy * sin(tab->anglex) + zz * cos(tab->anglex);
}

void	ft_rotate_y(t_main *tab, int *sx, int *sy, int *sz)
{
	int zx;
	int zy;
	int zz;

	zx = *sx;
	zy = *sy;
	zz = *sz;
	*sx = zx * cos(tab->angley) + zz * sin(tab->angley);
	*sy = zy;
	*sz = zx * -sin(tab->angley) + zz * cos(tab->angley);
}

void	ft_rotate_z(t_main *tab, int *sx, int *sy, int *sz)
{
	int zx;
	int zy;
	int zz;

	zx = *sx;
	zy = *sy;
	zz = *sz;
	*sx = zx * cos(tab->anglez) - zy * sin(tab->anglez);
	*sy = zx * sin(tab->anglez) + zy * cos(tab->anglez);
	*sz = zz;
}
