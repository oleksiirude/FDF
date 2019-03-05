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

void	make_hline(t_input *box, int delta_x, int delta_y)
{
	int error;

	error = -delta_x;
	while (box->a.x != box->b.x || box->a.y != box->b.y)
	{
		mlx_pixel_put(box->ptr, box->win,
				box->a.x, box->a.y, box->prm->color);
		box->a.x += box->dir.x;
		error += 2 * delta_y;
		if (error > 0)
		{
			error -= 2 * delta_x;
			box->a.y += box->dir.y;
		}
	}
}

void	make_vline(t_input *box, int delta_x, int delta_y)
{
	int error;

	error = -delta_y;
	while (box->a.y != box->b.y || box->a.x != box->b.x)
	{
		mlx_pixel_put(box->ptr, box->win,
				box->a.x, box->a.y, box->prm->color);
		box->a.y += box->dir.y;
		error += 2 * delta_x;
		if (error > 0)
		{
			error -= 2 * delta_y;
			box->a.x += box->dir.x;
		}
	}
}

void	painting_line(t_input *box)
{
	int delta_x;
	int delta_y;

	delta_x = abs(box->b.x - box->a.x);
	delta_y = abs(box->b.y - box->a.y);
	box->dir.x = box->b.x >= box->a.x ? 1 : -1;
	box->dir.y = box->b.y >= box->a.y ? 1 : -1;
	if (delta_y <= delta_x)
		make_hline(box, delta_x, delta_y);
	else
		make_vline(box, delta_x, delta_y);
	mlx_pixel_put(box->ptr, box->win, box->a.x,
			box->a.y, box->prm->color);
}
