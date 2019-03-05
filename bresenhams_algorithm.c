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

void	make_hline(t_input *box, int y_start, int x_start, int delta_x, int delta_y)
{
	int error;

	error = delta_x;
	while (x_start <= box->b.x || y_start <= box->b.y)
	{
		mlx_pixel_put(box->ptr, box->win,
				x_start, box->a.y, box->prm->color);
		x_start += box->dir.x;
		error += 2 *delta_y;
		if (error > 0)
		{
			error -= 2 * delta_x;
			y_start += box->dir.y;
		}
	}
}

void	make_vline(t_input *box, int x_start, int y_start, int delta_x, int delta_y)
{
	int error;

	error = -delta_y;
	while (y_start <= box->b.y || x_start <= box->b.x)
	{
		mlx_pixel_put(box->ptr, box->win,
				box->a.x, y_start, box->prm->color);
		y_start += box->dir.y;
		error += 2 * delta_x;
		if (error > 0)
		{
			error -= 2 * delta_y;
			x_start += box->dir.x;

		}
	}
}

void	painting_line(t_input *box, t_crd crd)
{
	int delta_x;
	int delta_y;

	delta_x = abs(box->b.x - box->a.x);
	delta_y = abs(box->b.y - box->a.y);
	box->dir.x = box->a.x < box->b.x ? 1 : -1;
	box->dir.y = box->a.y < box->b.y ? 1 : -1;
	if (crd.x < box->size.x)
		make_hline(box, box->a.y, box->a.x, delta_x, delta_y);
	if (crd.y < box->size.y)
		make_vline(box, box->a.x, box->a.y, delta_x, delta_y);
}