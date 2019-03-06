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

void	make_hline(t_input *box, t_crd delta, t_crd a, t_crd b)
{
	int error;

	error = -delta.x;
	while (a.x <= b.x)
	{
		mlx_pixel_put(box->ptr, box->win,
				a.x, a.y, box->prm->color);
		a.x += box->dir.x;
		error += 2 * delta.y;
		if (error > 0)
		{
			error -= 2 * delta.x;
			a.y += box->dir.y;
		}
	}
}

void	make_vline(t_input *box, t_crd delta, t_crd a, t_crd b)
{
	int error;

	error = -delta.y;
	while (a.y != b.y)
	{
		mlx_pixel_put(box->ptr, box->win,
				a.x, a.y, box->prm->color);
		a.y += box->dir.y;
		error += 2 * delta.x;
		if (error > 0)
		{
			error -= 2 * delta.y;
			a.x += box->dir.x;
		}
	}
}

void	painting_line(t_input *box, t_crd a, t_crd b)
{
	t_crd delta;

	delta.x = abs(b.x - a.x);
	delta.y = abs(b.y - a.y);
	box->dir.x = b.x >= a.x ? 1 : -1;
	box->dir.y = b.y >= a.y ? 1 : -1;
	if (delta.y <= delta.x)
		make_hline(box, delta, a, b);
	else
		make_vline(box, delta, a, b);
	mlx_pixel_put(box->ptr, box->win, a.x,
			a.y, box->prm->color);
}
