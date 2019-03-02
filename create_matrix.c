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

void	create_matrix(t_input **map, t_line *head, t_line *tail)
{
	int i;

	i = 0;
	(*map)->size.y = tail->size.y;
	(*map)->size.x = tail->size.x;
	(*map)->map = (int**)malloc(sizeof(int*) * (*map)->size.y);
	while (i < (*map)->size.y)
	{
		(*map)->map[i++] = create_row(head->line, (*map)->size.x);
		head = head->next;
	}
}
