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

void	setup3(int key, t_input *box)
{
	M_CL_M(key);
	M_CL_P(key);
	Z_CL_M(key);
	Z_CL_P(key);
	P_CL_M(key);
	P_CL_P(key);
	MOVE_M(key);
	MOVE_P(key);
	MENU(key);
	RESET(key);
}

void	setup2(int key, t_input *box)
{
	if (key == 125)
	{
		box->prm->init.y += 10;
		if (box->prm->init.y > 650)
			box->prm->init.y = 650;
	}
	ROT_X_P(key);
	ROT_X_M(key);
	ROT_Y_P(key);
	ROT_Y_M(key);
	ROT_Z_P(key);
	ROT_Z_M(key)
	ISO_PROJ(key);
	ORT_PROJ(key);
	SET_RED(key);
	SET_GREEN(key);
	SET_BLUE(key);
	ESCAPE(key);
	MOVE_RIGHT(key);
	MOVE_LEFT(key);
	setup3(key, box);
}

int	setup(int key, t_input *box)
{
	mlx_clear_window(box->ptr, box->win);
	if (key == 69)
	{
		box->prm->step += 1;
		box->prm->init.x -= box->size.x / 2;
		box->prm->init.y -= box->size.y / 2;
	}
	else if (key == 78 && box->prm->step > 0)
	{
		box->prm->step -= 1;
		box->prm->init.x += box->size.x / 2;
		box->prm->init.y += box->size.y / 2;
	}
	else if (key == 126)
	{
		box->prm->init.y -= 10;
		if (box->prm->init.y < 10)
			box->prm->init.y = 10;
	}
	setup2(key, box);
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
