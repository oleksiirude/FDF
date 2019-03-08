/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_x(t_input **box, t_crd global)
{
	if ((*box)->map[global.y][global.x] > 0
	&& (*box)->map[global.y][global.x - 1] > 0)
	{
		(*box)->prm->color = (*box)->prm->set_plus_color;
		if ((*box)->move < 0)
			(*box)->prm->color = (*box)->prm->set_minus_color;
	}
	else if ((*box)->map[global.y][global.x] < 0
	&& (*box)->map[global.y][global.x - 1] < 0)
	{
		(*box)->prm->color = (*box)->prm->set_minus_color;
		if ((*box)->move > 1)
			(*box)->prm->color = (*box)->prm->set_plus_color;
	}
	else if (!(*box)->map[global.y][global.x]
	&& !(*box)->map[global.y][global.x - 1])
		(*box)->prm->color = (*box)->prm->set_zero_color;
}

void	set_color_y(t_input **box, t_crd global)
{
	if ((*box)->map[global.y][global.x] > 0
	&& (*box)->map[global.y - 1][global.x] > 0)
	{
		(*box)->prm->color = (*box)->prm->set_plus_color;
		if ((*box)->move < 0)
			(*box)->prm->color = (*box)->prm->set_minus_color;
	}
	else if ((*box)->map[global.y][global.x] < 0
	&& (*box)->map[global.y - 1][global.x] < 0)
	{
		(*box)->prm->color = (*box)->prm->set_minus_color;
		if ((*box)->move > 1)
			(*box)->prm->color = (*box)->prm->set_plus_color;
	}
	else if (!(*box)->map[global.y][global.x]
	&& !(*box)->map[global.y - 1][global.x])
		(*box)->prm->color = (*box)->prm->set_zero_color;
}
