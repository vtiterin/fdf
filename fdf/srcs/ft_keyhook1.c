/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 14:28:00 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 14:28:03 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_main *tab)
{
	tab->image = mlx_new_image(tab->mlx, CW, CH);
	tab->ibuf = mlx_get_data_addr(tab->image, &(tab->icolor),
		&(tab->isize), &(tab->iendian));
	ft_wr_tab(tab);
	mlx_put_image_to_window(tab->mlx, tab->win, tab->image, 0, 0);
	mlx_string_put(tab->mlx, tab->win, 10, 10, 0xFFFFFF,
		"Press F1 to open/close legend");
	if (tab->options % 2)
		ft_pr_legend(tab);
	mlx_destroy_image(tab->mlx, tab->image);
	return (0);
}

int		key_hook(int keycode, t_main *tab)
{
	if (keycode == 53)
		exit(0);
	else
		my_key_func(keycode, tab);
	return (0);
}

void	my_key_func(int keycode, t_main *tab)
{
	if (keycode == 123)
		ft_im_left(tab);
	else if (keycode == 124)
		ft_im_right(tab);
	else if (keycode == 126)
		ft_im_up(tab);
	else if (keycode == 125)
		ft_im_down(tab);
	else if (keycode == 69)
		ft_zoom_up(tab);
	else if (keycode == 78)
		ft_zoom_down(tab);
	else if (keycode == 116)
		ft_zoom_up_z(tab);
	else if (keycode == 121)
		ft_zoom_down_z(tab);
	else if (keycode == 89)
		ft_rot_xp(tab);
	else if (keycode == 92)
		ft_rot_xm(tab);
	else
		my_key_func2(keycode, tab);
}

void	my_key_func2(int keycode, t_main *tab)
{
	if (keycode == 86)
		ft_rot_yp(tab);
	else if (keycode == 88)
		ft_rot_ym(tab);
	else if (keycode == 83)
		ft_rot_zp(tab);
	else if (keycode == 85)
		ft_rot_zm(tab);
	else if (keycode == 18)
		ft_color_b0(tab);
	else if (keycode == 19)
		ft_color_b1(tab);
	else if (keycode == 20)
		ft_color_b2(tab);
	else if (keycode == 21)
		ft_color_b3(tab);
	else if (keycode == 122)
		ft_legend(tab);
	else if (keycode == 87)
		ft_proj(tab);
}
