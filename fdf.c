/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_curent_matrix(t_input *box, t_crd crd, t_dcrd *calc)
{
	calc->x = box->mtrx[0][0] * (crd.x - box->size.x / 2);
	calc->x += box->mtrx[0][1] * (crd.y - box->size.y / 2);
	calc->x += box->mtrx[0][2] * box->map[crd.y][crd.x];
	calc->y = box->mtrx[1][0] * (crd.x - box->size.x / 2);
	calc->y += box->mtrx[1][1] * (crd.y - box->size.y / 2);
	calc->y += box->mtrx[1][2] * box->map[crd.y][crd.x];
	calc->x += box->size.x / 2;
	calc->y += box->size.y / 2;
}

void	get_ab_crd(t_input *box, t_dcrd crd, t_crd *buf, t_crd global)
{
	static int i = 0;

	i = !global.x ? 0 : i;
	box->b.x = box->prm->init.x + crd.x * box->prm->step;
	box->b.y = box->prm->init.y + crd.y * box->prm->step;
	if (global.x)
		bresenhams_algorithm(box, box->a, box->b);
	box->a.x = box->b.x;
	box->a.y = box->b.y;
	if (global.y)
		bresenhams_algorithm(box, box->a, buf[i]);
	buf[i].x = box->b.x;
	buf[i].y = box->b.y;
	i++;
}

void	launch_fdf(t_input *box)
{
	t_crd	crd;
	t_dcrd	calc;
	t_crd	*buf;

	ft_bzero(&crd, 8);
	buf = (t_crd*)malloc(sizeof(t_crd) * box->size.x);
	calc.y = 0;
	while (crd.y < box->size.y)
	{
		while (crd.x < box->size.x)
		{
			apply_curent_matrix(box, crd, &calc);
			get_ab_crd(box, calc, buf, crd);
			crd.x++;
		}
		crd.x = 0;
		crd.y++;
	}
}
