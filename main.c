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

int setup(int keycode, t_input *box)
{
	mlx_clear_window(box->ptr, box->win);
	ESCAPE(keycode);
	ZOOM_IN(keycode);
	ZOOM_OUT(keycode);
	MOVE_RIGHT(keycode);
	MOVE_LEFT(keycode);
	MOVE_UP(keycode);
	MOVE_DOWN(keycode);
	COLOR_FORWARD(keycode);
	COLOR_BACK(keycode);
	launch_fdf(box);
	return (0);
}

int	destroy(void)
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
	create_matrix(&box, head, lst, av[1]);
	launch_fdf(box);
	mlx_hook(box->win, 2, 0, setup, box);
	mlx_hook(box->win, 17, 0, destroy, NULL);
	mlx_loop(box->ptr);
	close_fd(&sys.fd, &sys.dir);
//	ft_print_intarr(box->map, box->size.y, box->size.x);
//	ft_printf("OK\n");
	return (0);
}
