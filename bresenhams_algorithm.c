/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_line(t_input *box, t_crd delta, t_crd a, t_crd b)
{
	int error;
	int error2;

	error = delta.x - delta.y;
	mlx_pixel_put(box->ptr, box->win,
			b.x, b.y, box->prm->color);
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(box->ptr, box->win, a.x, a.y, box->prm->color);
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			a.x += box->dir.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			a.y += box->dir.y;
		}
	}
}

void	bresenhams_algorithm(t_input *box, t_crd a, t_crd b)
{
	t_crd delta;

	delta.x = abs(b.x - a.x);
	delta.y = abs(b.y - a.y);
	box->dir.x = b.x >= a.x ? 1 : -1;
	box->dir.y = b.y >= a.y ? 1 : -1;
	make_line(box, delta, a, b);
}
