/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrlegend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:54:02 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:54:06 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pr_legend(t_main *tab)
{
	mlx_string_put(tab->mlx, tab->win, 10, 30,
		0xFFFFFF, "ESC          : quit");
	mlx_string_put(tab->mlx, tab->win, 10, 50,
		0xFFFFFF, "Arrows       : move");
	mlx_string_put(tab->mlx, tab->win, 10, 70,
		0xFFFFFF, "NUM +/-      : zoom");
	mlx_string_put(tab->mlx, tab->win, 10, 90,
		0xFFFFFF, "Num 7/9      : rotate around X");
	mlx_string_put(tab->mlx, tab->win, 10, 110,
		0xFFFFFF, "Num 4/6      : rotate around Y");
	mlx_string_put(tab->mlx, tab->win, 10, 130,
		0xFFFFFF, "Num 1/3      : rotate around Z");
	mlx_string_put(tab->mlx, tab->win, 10, 150,
		0xFFFFFF, "PgUp/PgDn    : adjust height");
	mlx_string_put(tab->mlx, tab->win, 10, 170,
		0xFFFFFF, "Num 5        : change projection");
	mlx_string_put(tab->mlx, tab->win, 10, 190,
		0xFFFFFF, "Keys 1/2/3/4 : change collor");
	mlx_string_put(tab->mlx, tab->win, 10, 210, tab->col->col0, "collor1");
	mlx_string_put(tab->mlx, tab->win, 90, 210, tab->col->col1, "collor2");
	mlx_string_put(tab->mlx, tab->win, 170, 210, tab->col->col2, "collor3");
	mlx_string_put(tab->mlx, tab->win, 250, 210, tab->col->col3, "collor4");
}
