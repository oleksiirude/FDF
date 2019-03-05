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

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "keymap.h"
# include "./libft/inc/libft.h"

typedef struct		s_crd
{
	int				x;
	int				y;
}					t_crd;

typedef struct		s_data
{
	struct s_crd	init;
	int 			color;
	int				step;
	int 			z;
}					t_data;

typedef struct		s_sys
{
	int				fd;
	int				dir;
}					t_sys;

typedef struct		s_line
{
	struct s_crd	size;
	char 			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_input
{
	void			*ptr;
	void			*win;
	struct s_crd	a;
	struct s_crd	b;
	struct s_crd	dir;
	struct s_crd	size;
	struct s_data	*prm;
	int 			**map;
}					t_input;

int					atoi_ptr(char **str);
int					skip_hex(char **line);
int					free_line(char **line);
int					free_lst(t_line **head);
void				show_menu(t_input *box);
void				launch_fdf(t_input *map);
void				close_fd(int *fd, int *dir);
int					parse_map(t_line **lst, int fd);
void				set_color(t_input *box, int sign);
int					free_and_error_handling(t_line	**head);
int					error_manage(int dir, char *title, int ac, int error);
void 				create_matrix(t_input **map, t_line *head, t_line *tail, char *title);
void				painting_line(t_input *box, t_crd crd);
#endif

//lx_string_put(box->ptr, box->win, 700, 500, 1361940, "Hello!");