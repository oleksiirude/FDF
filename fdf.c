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

void	print_struct_arr(t_crd *buf, t_input *box)
{
	int i;

	i = -1;
	while (++i < box->size.x)
		ft_printf("buf[%d] x->%d, y->%d\n", i, buf[i].x, buf[i].y);
}

void	get_line(t_input *box, t_crd crd, t_crd *buf)
{
	static int i = 0;

	i = !crd.x ? 0 : i;
	box->b.x = box->prm->init.x + crd.x * box->prm->step;
	box->b.y = box->prm->init.y + crd.y * box->prm->step;
	if (crd.x)
		painting_line(box, box->a, box->b);
	box->a.x = box->b.x;
	box->a.y = box->b.y;
	if (crd.y)
		painting_line(box, box->a, buf[i]);
	buf[i].x = box->b.x;
	buf[i].y = box->b.y;
	i++;
//	ft_printf("x-> %d %d\n", box->a.x, box->b.x);
//	ft_printf("y-> %d %d\n\n", box->a.y, box->b.y);
}

void	launch_fdf(t_input *box)
{
	t_crd	crd;
	t_crd	*buf;

	ft_bzero(&crd, 8);
	buf = (t_crd*)malloc(sizeof(t_crd) * box->size.x);
	while (crd.y <= box->size.y)
	{
		while (crd.x <= box->size.x)
		{
			get_line(box, crd, buf);
			crd.x++;
		}
		ft_printf("go next\n");
		//print_struct_arr(buf, box);
		crd.x = 0;
		crd.y++;
	}
}
