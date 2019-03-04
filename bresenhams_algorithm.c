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

void	make_hline(t_input *box, int x_start)
{
	while (x_start <= box->b.x)
	{
		mlx_pixel_put(box->ptr, box->win,
				x_start, box->a.y, box->prm->color);
		x_start++;
	}
}

void	make_vline(t_input *box, int y_start)
{
	while (y_start <= box->b.y)
	{
		mlx_pixel_put(box->ptr, box->win,
				box->a.x, y_start, box->prm->color);
		y_start++;
	}
}

void	painting_line(t_input *box, t_crd crd)
{
	if (crd.x < box->size.x)
		make_hline(box, box->a.x);
	if (crd.y < box->size.y)
		make_vline(box, box->a.y);
}