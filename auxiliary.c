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

void	show_menu(t_input *box)
{
	mlx_string_put(box->ptr, box->win, 1600, 6, 1361940,
			"Menu bar");
	mlx_string_put(box->ptr, box->win, 1500, 20, 13158600,
			"1. Map move: control arrows");
	mlx_string_put(box->ptr, box->win, 1500, 40, 13158600,
			"2. Red color: 'R'");
	mlx_string_put(box->ptr, box->win, 1500, 60, 13158600,
			"3. Green color: 'G'");
	mlx_string_put(box->ptr, box->win, 1500, 80, 13158600,
			"4. Blue color: 'B'");
	mlx_string_put(box->ptr, box->win, 1500, 100, 13158600,
			"5. Play with color: 'C' && 'V'");
	mlx_string_put(box->ptr, box->win, 1500, 120, 13158600,
			"6. Zoom in: '-' (num zone)");
	mlx_string_put(box->ptr, box->win, 1500, 140, 13158600,
			"7. Zoom out: '+' (num zone)");
	mlx_string_put(box->ptr, box->win, 1500, 160, 13158600,
			"8. Increase height: 'Z'");
	mlx_string_put(box->ptr, box->win, 1500, 180, 13158600,
			"9. Decrease height: 'X'");
	mlx_string_put(box->ptr, box->win, 1500, 200, 13158600,
			"10. Quit: 'Q'");
}

void	set_color(t_input *box, int sign)
{
	if (sign)
		box->prm->color += 5;
	else
		box->prm->color -= 5;
}

int		atoi_ptr(char **str)
{
	long long	res;
	int			minus;

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
		res = res > 300 ? 300 : res;
		return ((int)(res * minus));
	}
	return (0);
}
