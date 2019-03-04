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

void	do_hline(t_input *box, int deltay, int deltax, int error)
{
	static int counter;

	counter = 0;
	error = deltax * -1;
	while (box->a.y != box->b.y)
	{
//		ft_printf("hline\n");
//		ft_printf("%d\n", counter);
		mlx_pixel_put(box->ptr, box->win, box->a.x,
				box->a.y, box->prm->color);
		box->a.x += box->direction.x;
		error += 2 * deltay;
		if (error > 0)
		{
			error -= 2 * deltax;
			box->a.y += box->direction.y;
		}
	}
	counter++;
}

void	do_vline(t_input *box, int deltay, int deltax, int error)
{
	static int counter;

	counter = 0;
	error = deltay * -1;
//	ft_printf("1. %d != %d || %d != %d\n", box->a.y, box->b.y, box->a.x, box->b.x);
	while (box->a.x != box->b.x)
	{
//		ft_printf("vline\n");
//		ft_printf("2. %d != %d || %d != %d\n", box->a.y, box->b.y, box->a.x, box->b.x);
//		if (counter == 3)
//			exit(1);
		mlx_pixel_put(box->ptr, box->win, box->a.x,
					  box->a.y, box->prm->color);
		box->a.y += box->direction.y;
		error += 2 * deltax;
		if (error > 0)
		{
			error -= 2* deltay;
			box->a.x += box->direction.x;
		}
		counter++;
	}
}

void	painting_line(t_input *box, t_crd crd)
{
	int error;
	int deltay;
	int deltax;

	deltay = myabs(box->b.x - box->a.x);
	deltax = myabs(box->b.y - box->a.y);
	box->direction.x = box->b.x >= box->a.x ? 1 : -1;
	box->direction.y = box->b.y >= box->a.y ? 1 : -1;
	mlx_pixel_put(box->ptr, box->win, box->a.y, box->a.x, box->prm->color);
//	if (deltax <= deltay)
//		do_hline(box, deltay, deltax, error);
//	else
//		do_vline(box, deltay, deltax, error);
}