/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:55:02 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/24 13:55:04 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_intlen(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int		ft_words(char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			words++;
		while (*str && *str != c)
			str++;
	}
	return (words);
}

void	ft_up_str(char **buf, int l, char *line)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*buf);
	tmp = ft_strnew(len + l);
	ft_strncpy(tmp, *buf, len);
	ft_strncat(tmp, line, l);
	free(*buf);
	*buf = ft_strnew(len + l + 1);
	ft_strncpy(*buf, tmp, len + l);
	ft_strncat(*buf, " ", 1);
	free(tmp);
}

char	*read_matrix(char *arvg, int *h, int *w)
{
	char	*ret;
	char	*buf;
	int		fd;

	*w = 0;
	*h = 0;
	ret = ft_strnew(0);
	if ((fd = open(arvg, O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	while (get_next_line(fd, &buf))
	{
		ft_up_str(&ret, ft_strlen(buf), buf);
		if (*w == 0)
			*w = ft_words(buf, ' ');
		(*h)++;
		free(buf);
	}
	free(buf);
	close(fd);
	return (ret);
}

void	ft_frtab(char **cord)
{
	int i;

	i = 0;
	while (cord[i])
	{
		free(cord[i]);
		i++;
	}
	free(cord);
}
