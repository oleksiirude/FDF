/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/08 19:23:42 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	to_zero(t_crd *a, t_crd *b, t_crd *c)
{
	ft_bzero(a, 8);
	ft_bzero(b, 8);
	ft_bzero(c, 8);
}

void	free_double_arr(double **arr)
{
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
}

void	close_fd(int *fd, int *dir)
{
	close(*fd);
	close(*dir);
}

int		free_line(char **line)
{
	free(*line);
	return (0);
}

int		free_lst(t_line **head)
{
	t_line *tmp;

	while ((*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->line);
		free(tmp);
	}
	return (0);
}
