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

int main(int ac, char **av)
{
   	t_sys	sys;
   	t_line	*lst;
   	t_line	*head;
   	t_input	*map;

   	ac = 2;
   	sys.dir = open(av[1], O_DIRECTORY);
//   sys.fd = open(av[1], O_RDONLY);
	sys.fd = open("./test_maps/42.fdf", O_RDONLY);
//	sys.fd = open("./test_maps/pyramide.fdf", O_RDONLY);
	if (ac != 2 || sys.dir > 0 || sys.fd < 0)
		return (error_manage(sys.dir, av[1], ac, sys.fd));
	lst = (t_line*)malloc(sizeof(t_line));
	lst->next = NULL;
	head = lst;
	if(!parse_map(&lst, sys.fd, av[1]))
		return (free_and_error_handling(&head));
	while (head->next)
	{
		ft_printf("y->%2d, row->%s\n", head->y, head->row);
		head = head->next;
	}
	map = (t_input*)malloc(sizeof(t_input));
	map->map = (int**)malloc(sizeof(int*));
	map->map = convert_to_intarr(map);
//	free_chararr(&map);
//	fdf_launch(map);
	close(sys.dir);
	close(sys.fd);
//	system("leaks -q FDF");
	return 0;
}