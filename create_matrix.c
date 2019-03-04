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

	str = "olrudenk's FDF | map: ";
	str = ft_strjoin(str, title);
	(*box)->prm = (t_data*)malloc(sizeof(t_data));
	(*box)->prm->init.x = 100;
	(*box)->prm->init.y = 100;
	(*box)->prm->color = 1361940;
	(*box)->prm->step = 30;
	if ((*box)->prm->step < 10)
		(*box)->prm->step = 10;
	(*box)->prm->z = 0;
	(*box)->ptr = mlx_init();
	(*box)->win = mlx_new_window((*box)->ptr, 1400, 1000, str);
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

void	create_matrix(t_input **box, t_line *head, t_line *tail, char *title)
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
	set_up_data(box, title);
	free_lst(&start);
}
