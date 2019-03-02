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

void	get_hline(t_input *box, t_crd crd)
{
	box->a.y = box->prm->init.y + (crd.y * box->prm->step);
	box->a.x = box->prm->init.x + (crd.x * box->prm->step)
			- box->map[crd.y][crd.x] * box->prm->z;
	box->b.y = box->prm->init.y + ((crd.y + 1) * box->prm->step);
	box->b.x = box->prm->init.x + (crd.x * box->prm->step)
			- box->map[crd.y][crd.x] * box->prm->z;
	write(1, "hOK\n", 4);
//	ft_printf("Horizontal line:\n");
//	ft_printf("start y[%d], x[%d]\n", box->a.y, box->a.x);
//	ft_printf("end   y[%d], x[%d]\n\n", box->b.y, box->b.x);
	painting_line(box, crd);
}

void	get_vline(t_input *box, t_crd crd)
{
	box->a.y = box->prm->init.y + (crd.y * box->prm->step);
	box->a.x = box->prm->init.x + (crd.x * box->prm->step)
				   - box->map[crd.y][crd.x] * box->prm->z;
	box->b.y = box->prm->init.y + (crd.y * box->prm->step);
	box->b.x = box->prm->init.x + ((crd.x + 1) * box->prm->step)
				   - box->map[crd.y][crd.x] * box->prm->z;
//	ft_printf("Vertical line:\n");
//	ft_printf("start y[%d], x[%d]\n", box->a.y, box->a.x);
//	ft_printf("end   y[%d], x[%d]\n\n", box->b.y, box->b.x);
	painting_line(box, crd);
}

void	launch_fdf(t_input *box)
{
	t_crd	crd;

	ft_bzero(&crd, 8);
	while (crd.y < box->size.y)
	{
		while (crd.x < box->size.x)
		{
				get_vline(box, crd);
				get_hline(box, crd);
			crd.x++;
		}
		crd.x = 0;
		crd.y++;
	}
}