/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_up_data(t_input **box, char *title)
{
	char *str;
	char *menu;

	menu = "													"
		"				[press 'M' to see menu bar]";
	str = "olrudenk's FDF | map: ";
	str = ft_strjoin(str, title);
	str = ft_strjoin(str, menu);
	(*box)->prm = (t_data*)malloc(sizeof(t_data));
	(*box)->prm->init.x = 500;
	(*box)->prm->init.y = 300;
	(*box)->prm->color = 1361940;
	(*box)->prm->step = 20;
	(*box)->prm->rad = 2 * 3.14 / 180;
	(*box)->ptr = mlx_init();
	(*box)->win = mlx_new_window((*box)->ptr, 1200, 1000, str);
}

double 	**set_up_base_mtrx(void)
{
	int		i;
	double	**base_mtrx;

	i = -1;
	base_mtrx = (double**)malloc(sizeof(double*) * 3);
	while (++i < 3)
		base_mtrx[i] = (double*)malloc(sizeof(double) * 3);
	base_mtrx[0][0] = 1;
	base_mtrx[0][1] = 0;
	base_mtrx[0][2] = 0;
	base_mtrx[1][0] = 0;
	base_mtrx[1][1] = 1;
	base_mtrx[1][2] = 0;
	base_mtrx[2][0] = 0;
	base_mtrx[2][1] = 0;
	base_mtrx[2][2] = 1;
	return (base_mtrx);
}

int		*create_row(char *line, int x)
{
	int i;
	int *row;

	i = 0;
	row = (int*)malloc(sizeof(int) * x);
	while (*line)
	{
		row[i++] = atoi_ptr(&line);
		if (*line == ',')
			skip_hex(&line);
	}
	return (row);
}

void	create_map(t_input **box, t_line *head, t_line *tail, char *title)
{
	int		i;
	t_line	*start;

	i = 0;
	start = head;
	(*box)->size.y = tail->size.y;
	(*box)->size.x = tail->size.x;
	(*box)->map = (int**)malloc(sizeof(int*) * (*box)->size.y);
	while (i < (*box)->size.y)
	{
		(*box)->map[i++] = create_row(head->line, (*box)->size.x);
		head = head->next;
	}
	(*box)->mtrx = set_up_base_mtrx();
	set_up_data(box, title);
	free_lst(&start);
}
