/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	free_line(char **line)
{
	free(*line);
	return (0);
}

int		atoi_ptr(char **str)
{
	int	res;
	int minus;

	res = 0;
	minus = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			minus = -1;
		(*str)++;
	}
	while (**str)
	{
		while (**str >= '0' && **str <= '9')
		{
			res = 10 * res + (**str - '0');
			(*str)++;
		}
		return (res * minus);
	}
	return (0);
}

int **convert_to_intarr(t_input *map)
{

}