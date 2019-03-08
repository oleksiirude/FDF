/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		to_zero(t_crd *a, t_crd *b, t_crd *c)
{
	ft_bzero(a, 8);
	ft_bzero(b, 8);
	ft_bzero(c, 8);
}

double		**matrixs_multiplication(double **a, double b[3][3])
{
	t_crd	am;
	t_crd	bm;
	t_crd	cm;
	double	**c;

	c = set_up_base_mtrx();
	to_zero(&am, &bm, &cm);
	while (am.y < 3)
	{
		cm.x = 0;
		while (cm.x < 3)
		{
			c[cm.y][cm.x] = a[am.y][am.x++] * b[bm.y++][bm.x];
			c[cm.y][cm.x] += a[am.y][am.x++] * b[bm.y++][bm.x];
			c[cm.y][cm.x++] += a[am.y][am.x] * b[bm.y][bm.x];
			am.x = 0;
			bm.y = 0;
			bm.x++;
		}
		am.y++;
		bm.x = 0;
		cm.y++;
	}
	return (c);
}

void		show_menu(t_input *box)
{
	mlx_string_put(box->ptr, box->win, 1185, 2, 1361940,
			"Menu bar");
	mlx_string_put(box->ptr, box->win, 1030, 20, 13158600,
			"1. Map move: control arrows");
	mlx_string_put(box->ptr, box->win, 1030, 40, 13158600,
			"2. RGB zero surface: 'R', 'G', 'B'");
	mlx_string_put(box->ptr, box->win, 1030, 60, 13158600,
			"4. Color play '+' surface: 'Q' && 'W'");
	mlx_string_put(box->ptr, box->win, 1030, 80, 13158600,
			"5. Color play '0' surface: 'A' && 'S'");
	mlx_string_put(box->ptr, box->win, 1030, 100, 13158600,
			"6. Color play '-' surface: 'Z' && 'X'");
	mlx_string_put(box->ptr, box->win, 1030, 120, 13158600,
			"NUM zone:");
	mlx_string_put(box->ptr, box->win, 1030, 140, 13158600,
			"7. Rotate x: '7' && '8'");
	mlx_string_put(box->ptr, box->win, 1030, 160, 13158600,
			"8. Rotate y: '4' && '5'");
	mlx_string_put(box->ptr, box->win, 1030, 180, 13158600,
			"9. Rotate z: '1' && '2'");
	mlx_string_put(box->ptr, box->win, 1030, 200, 13158600,
			"10. Zoom in/out: '+' && '-'");
	mlx_string_put(box->ptr, box->win, 1030, 220, 13158600,
			"7. Quit: 'esc'");
}

int			atoi_ptr(char **str)
{
	long long	res;
	int			minus;

	res = 0;
	minus = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			minus = -1;
		(*str)++;
	}
	while (**str)
	{
		while (**str >= '0' && **str <= '9')
		{
			res = 10 * res + (**str - '0');
			(*str)++;
		}
		res = res > 300 ? 300 : res;
		return ((int)(res * minus));
	}
	return (0);
}
