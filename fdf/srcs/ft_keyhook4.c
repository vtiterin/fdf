/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:47:10 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:47:14 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_zp(t_main *tab)
{
	tab->anglez += 0.2;
	expose_hook(tab);
}

void	ft_rot_zm(t_main *tab)
{
	tab->anglez -= 0.2;
	expose_hook(tab);
}

void	ft_legend(t_main *tab)
{
	tab->options += 1;
	expose_hook(tab);
}

void	ft_proj(t_main *tab)
{
	tab->proj += 1;
	expose_hook(tab);
}

void	ft_zoom_down(t_main *tab)
{
	if (sqrt(pow(tab->w * tab->scale, 2) +
		pow(tab->h * tab->scale, 2)) > CW / 2)
		tab->scale = tab->scale - 1;
	expose_hook(tab);
}
