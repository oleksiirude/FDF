/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	setup(int key, t_input *box)
{
	mlx_clear_window(box->ptr, box->win);
	if (key == 89)
		box->mtrx = rot_x(&box, 1);
	else if (key == 91)
		box->mtrx = rot_x(&box, -1);
	else if (key == 86)
		box->mtrx = rot_y(&box, 1);
	else if (key == 87)
		box->mtrx = rot_y(&box, -1);
	else if (key == 83)
		box->mtrx = rot_z(&box, 1);
	else if (key == 84)
		box->mtrx = rot_z(&box, -1);
	else if (key == 2)
		reset_to_default(&box);
	else if (key == 34)
		box->mtrx = isometric_pojection(&box);
	else if (key == 31)
		box->mtrx = orthogonal_side(&box);
	else if (key == 12)
		box->prm->set_plus_color +=5;
	else if (key == 13)
		box->prm->set_plus_color -=5;
	else if (key == 0)
		box->prm->set_zero_color +=5;
	else if (key == 1)
		box->prm->set_zero_color -=5;
	else if (key == 6)
		box->prm->set_minus_color +=5;
	else if (key == 7)
		box->prm->set_minus_color -=5;
	SET_RED(key);
	SET_GREEN(key);
	SET_BLUE(key);
	ESCAPE(key);
	ZOOM_IN(key);
	ZOOM_OUT(key);
	MOVE_RIGHT(key);
	MOVE_LEFT(key);
	MOVE_UP(key);
	MOVE_DOWN(key);
	SHOW_MENU(key);
	launch_fdf(box);
	return (0);
}

int	exit_from_fdf(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_sys	sys;
	t_line	*lst;
	t_line	*head;
	t_input	*box;

	sys.fd = open(av[1], O_RDONLY);
	sys.dir = open(av[1], O_DIRECTORY);
	if (ac != 2 || sys.dir > 0 || sys.fd < 0)
		return (error_manage(sys.dir, av[1], ac, sys.fd));
	lst = (t_line*)malloc(sizeof(t_line));
	lst->next = NULL;
	head = lst;
	if (!parse_map(&lst, sys.fd))
		return (free_and_error_handling(&head));
	box = (t_input*)malloc(sizeof(t_input));
	create_map(&box, head, lst, av[1]);
	launch_fdf(box);
	mlx_hook(box->win, 2, 0, setup, box);
	mlx_hook(box->win, 17, 0, exit_from_fdf, NULL);
	mlx_loop(box->ptr);
	close_fd(&sys.fd, &sys.dir);
	return (0);
}
