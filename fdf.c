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

void	get_line(t_input *box, t_crd crd)
{
	box->a.x = box->prm->init.x + (crd.x * box->prm->step);
	box->b.x = box->prm->init.x + ((crd.x + 1) * box->prm->step);

	box->a.y = box->prm->init.y + (crd.y * box->prm->step);
	box->b.y = box->prm->init.y + ((crd.y + 1) * box->prm->step);
	painting_line(box, crd);
}

void	launch_fdf(t_input *box)
{
	t_crd	crd;

	ft_bzero(&crd, 8);
	while (crd.y <= box->size.y)
	{
		while (crd.x <= box->size.x)
		{
			get_line(box, crd);
			crd.x++;
		}
		crd.x = 0;
		crd.y++;
	}
}