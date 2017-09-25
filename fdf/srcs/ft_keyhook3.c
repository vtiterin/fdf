/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:46:54 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:46:57 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_down_z(t_main *tab)
{
	tab->scalez -= 0.05;
	expose_hook(tab);
}

void	ft_rot_xp(t_main *tab)
{
	tab->anglex += 0.2;
	expose_hook(tab);
}

void	ft_rot_xm(t_main *tab)
{
	tab->anglex -= 0.2;
	expose_hook(tab);
}

void	ft_rot_yp(t_main *tab)
{
	tab->angley += 0.2;
	expose_hook(tab);
}

void	ft_rot_ym(t_main *tab)
{
	tab->angley -= 0.2;
	expose_hook(tab);
}
