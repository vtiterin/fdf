/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:46:46 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:46:48 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_im_left(t_main *tab)
{
	tab->ox = tab->ox - tab->scale;
	expose_hook(tab);
}

void	ft_im_right(t_main *tab)
{
	tab->ox = tab->ox + tab->scale;
	expose_hook(tab);
}

void	ft_im_up(t_main *tab)
{
	tab->oy = tab->oy - tab->scale;
	expose_hook(tab);
}

void	ft_im_down(t_main *tab)
{
	tab->oy = tab->oy + tab->scale;
	expose_hook(tab);
}

void	ft_zoom_up_z(t_main *tab)
{
	tab->scalez += 0.05;
	expose_hook(tab);
}
