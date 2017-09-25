/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chcollor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:51:39 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:51:43 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_main *tab, int z)
{
	int m;

	m = tab->maxz / 2 / 2;
	if (z >= tab->maxz / 2 + m)
		return (tab->col->col3);
	else if (z >= tab->maxz / 2 - m && z < tab->maxz / 2 + m)
		return (tab->col->col2);
	else if (z <= tab->maxz / 2 + m - m && z >= 0)
		return (tab->col->col1);
	else
		return (tab->col->col0);
}

void	ft_col0(t_main *tab, int i)
{
	if (i % 5 == 0)
		tab->col->col0 = 0x0041FF;
	else if (i % 5 == 1)
		tab->col->col0 = 0x00CED1;
	else if (i % 5 == 2)
		tab->col->col0 = 0x7FFFD4;
	else if (i % 5 == 3)
		tab->col->col0 = 0x000080;
	else if (i % 5 == 4)
		tab->col->col0 = 0x556B2F;
}

void	ft_col1(t_main *tab, int i)
{
	if (i % 5 == 0)
		tab->col->col1 = 0x25FF50;
	else if (i % 5 == 1)
		tab->col->col1 = 0x006400;
	else if (i % 5 == 2)
		tab->col->col1 = 0xFFDEAD;
	else if (i % 5 == 3)
		tab->col->col1 = 0x778899;
	else if (i % 5 == 4)
		tab->col->col1 = 0x8B4513;
}

void	ft_col2(t_main *tab, int i)
{
	if (i % 5 == 0)
		tab->col->col2 = 0xAD4F09;
	else if (i % 5 == 1)
		tab->col->col2 = 0x00BFFF;
	else if (i % 5 == 2)
		tab->col->col2 = 0x8B7355;
	else if (i % 5 == 3)
		tab->col->col2 = 0x8B6969;
	else if (i % 5 == 4)
		tab->col->col2 = 0x8B7D6B;
}

void	ft_col3(t_main *tab, int i)
{
	if (i % 5 == 0)
		tab->col->col3 = 0xFFFFFF;
	else if (i % 5 == 1)
		tab->col->col3 = 0xB0C4DE;
	else if (i % 5 == 2)
		tab->col->col3 = 0x00FFFF;
	else if (i % 5 == 3)
		tab->col->col3 = 0xB8860B;
	else if (i % 5 == 4)
		tab->col->col3 = 0xFFD700;
}
