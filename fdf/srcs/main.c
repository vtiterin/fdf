/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:16:56 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/20 08:16:59 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ini(t_main *tab, char **arg)
{
	tab->mlx = mlx_init();
	tab->win = mlx_new_window(tab->mlx, CW, CH, "fdf");
	tab->maxz = 0;
	tab->col->col0 = 0x0041FF;
	tab->col->col1 = 0x25FF50;
	tab->col->col2 = 0xAD4F09;
	tab->col->col3 = 0xFFFFFF;
	tab->ox = CW / 2;
	tab->oy = CH / 2;
	tab->scalez = 0.3;
	tab->anglex = 0;
	tab->angley = 0;
	tab->anglez = 0;
	tab->col->p0 = 0;
	tab->col->p1 = 0;
	tab->col->p2 = 0;
	tab->col->p3 = 0;
	tab->sx = 0;
	tab->sy = 0;
	tab->sz = 0;
	tab->options = 0;
	tab->proj = 0;
	tab->tab = cord_tab(arg[1], &tab->w, &tab->h, &tab->maxz);
	ft_base_scale(tab);
}

int		main(int ar, char **arg)
{
	t_main *tab;

	if (ar == 2)
	{
		if (!(tab = (t_main*)malloc(sizeof(t_main))))
			return (1);
		if (!(tab->col = (t_col*)malloc(sizeof(t_col))))
			return (1);
		ft_ini(tab, arg);
		mlx_key_hook(tab->win, key_hook, tab);
		mlx_expose_hook(tab->win, expose_hook, tab);
		mlx_loop(tab->mlx);
	}
	else
	{
		ft_putstr("Incorrect number of arguments\n");
		return (1);
	}
	return (0);
}
