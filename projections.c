/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/08 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**isometric_pojection(t_input **box)
{
	double **iso_mtrx;
	double iso_pr[3][3];

	free((*box)->mtrx);
	(*box)->mtrx = set_up_base_mtrx();
	iso_pr[0][0] = 0.719610;
	iso_pr[0][1] = -0.694378;
	iso_pr[0][2] = -0.000000;
	iso_pr[1][0] = 0.561894;
	iso_pr[1][1] = 0.582312;
	iso_pr[1][2] = -0.587528;
	iso_pr[2][0] = 0.407966;
	iso_pr[2][1] = 0.422791;
	iso_pr[2][2] = 0.809204;
	iso_mtrx = matrixs_multiplication((*box)->mtrx, iso_pr);
	free_double_arr((*box)->mtrx);
	return (iso_mtrx);
}

double	**orthogonal_side(t_input **box)
{
	double **ort_side_mtrx;
	double ort_side[3][3];

	free((*box)->mtrx);
	(*box)->mtrx = set_up_base_mtrx();
	ort_side[0][0] = 1.000000;
	ort_side[0][1] = 0.000000;
	ort_side[0][2] = 0.000000;
	ort_side[1][0] = 0.000000;
	ort_side[1][1] = 0.000796;
	ort_side[1][2] = -1.000000;
	ort_side[2][0] = 1.000000;
	ort_side[2][1] = 1.000000;
	ort_side[2][2] = 1.000796;
	ort_side_mtrx = matrixs_multiplication((*box)->mtrx, ort_side);
	free_double_arr((*box)->mtrx);
	return (ort_side_mtrx);
}
