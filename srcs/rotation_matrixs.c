/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrixs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/08 19:19:43 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	**rot_x(t_input **box, int sign)
{
	double **newmtrx;
	double rot_x[3][3];

	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(sign * (*box)->prm->rad);
	rot_x[1][2] = -sin(sign * (*box)->prm->rad);
	rot_x[2][0] = 0;
	rot_x[2][1] = sin(sign * (*box)->prm->rad);
	rot_x[2][2] = cos(sign * (*box)->prm->rad);
	newmtrx = matrixs_multiplication((*box)->mtrx, rot_x);
	free_double_arr((*box)->mtrx);
	return (newmtrx);
}

double	**rot_y(t_input **box, int sign)
{
	double **newmtrx;
	double rot_y[3][3];

	rot_y[0][0] = cos(sign * (*box)->prm->rad);
	rot_y[0][1] = 0;
	rot_y[0][2] = sin(sign * (*box)->prm->rad);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 0;
	rot_y[2][0] = -sin(sign * (*box)->prm->rad);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(sign * (*box)->prm->rad);
	newmtrx = matrixs_multiplication((*box)->mtrx, rot_y);
	free_double_arr((*box)->mtrx);
	return (newmtrx);
}

double	**rot_z(t_input **box, int sign)
{
	double **newmtrx;
	double rot_z[3][3];

	rot_z[0][0] = cos(sign * (*box)->prm->rad);
	rot_z[0][1] = -sin(sign * (*box)->prm->rad);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(sign * (*box)->prm->rad);
	rot_z[1][1] = cos(sign * (*box)->prm->rad);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
	newmtrx = matrixs_multiplication((*box)->mtrx, rot_z);
	free_double_arr((*box)->mtrx);
	return (newmtrx);
}
