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

//void	get_line(t_input *box, t_crd crd, int n1, int n2)
//{
//	box->a.x = box->prm->init.x + (crd.x * box->prm->step);
//	box->b.x = box->prm->init.x + ((crd.x + n1) * box->prm->step);
//
//	box->a.y = box->prm->init.y + (crd.y * box->prm->step) - box->map[crd.y][crd.x] * box->prm->z;
//	box->b.y = box->prm->init.y + ((crd.y + n2) * box->prm->step) - box->map[crd.y + n2][crd.x + n1] * box->prm->z;
//	painting_line(box);
//}

void	get_line(t_input *box, t_crd crd, int n1, int n2)
{
	box->a.x = box->prm->init.x + (crd.x * box->prm->step) - box->map[crd.y][crd.x] * box->prm->h;
	box->b.x = box->prm->init.x + ((crd.x + n1) * box->prm->step) - box->map[crd.y + n2][crd.x + n1] * box->prm->h;

	box->a.y = box->prm->init.y + (crd.y * box->prm->step) - box->map[crd.y][crd.x] * box->prm->v;
	box->b.y = box->prm->init.y + ((crd.y + n2) * box->prm->step) - box->map[crd.y + n2][crd.x + n1] * box->prm->v;;
	painting_line(box);
}

void	launch_fdf(t_input *box)
{
	t_crd			crd;

	ft_bzero(&crd, 8);
	while (crd.y < box->size.y)
	{
		while (crd.x < box->size.x)
		{
			if (crd.x < box->size.x - 1)
				get_line(box, crd, 1, 0);
			if (crd.y < box->size.y - 1)
				get_line(box, crd, 0, 1);
			crd.x++;
		}
		crd.x = 0;
		crd.y++;
	}
}
