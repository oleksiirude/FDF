/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/inc/libft.h"

typedef struct		s_sys
{
	int				fd;
	int				dir;
}					t_sys;

typedef struct		s_crd
{
	int				y;
	int				x;
}					t_crd;

typedef struct		s_line
{
	struct s_crd	size;
	char 			*line;
	struct	s_line	*next;
}					t_line;

typedef struct		s_input
{
	struct s_crd	size;
	int 			**map;
}					t_input;

int					atoi_ptr(char **str);
int					free_line(char **line);
int					free_lst(t_line **head);
int					skip_hex(char **line);
int					parse_map(t_line **lst, int fd);
int					free_and_error_handling(t_line	**head);
int					error_manage(int dir, char *title, int ac, int error);
void 				create_matrix(t_input **map, t_line *head, t_line *tail);
#endif
