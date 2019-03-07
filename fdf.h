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
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "keymap.h"
# include "./libft/inc/libft.h"

typedef struct		s_dcrd
{
	double				x;
	double				y;
}					t_dcrd;

typedef struct		s_crd
{
	int				x;
	int				y;
}					t_crd;

typedef struct		s_data
{
	struct s_crd	init;
	int				color;
	int				step;
	double 			rad;
}					t_data;

typedef struct		s_sys
{
	int				fd;
	int				dir;
}					t_sys;

typedef struct		s_line
{
	struct s_crd	size;
	char			*line;
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
	int				**map;
	double 			**mtrx;
}					t_input;

int					atoi_ptr(char **str);
int					skip_hex(char **line);
int					free_line(char **line);
int					free_lst(t_line **head);
void				free_double_arr(double **arr);
void				show_menu(t_input *box);
void				launch_fdf(t_input *map);
void				close_fd(int *fd, int *dir);
int					parse_map(t_line **lst, int fd);
void				set_color(t_input *box, int sign);
int					free_and_error_handling(t_line	**head);
int					error_manage(int dir, char *title, int ac, int error);
void				create_map(t_input **map, t_line *head,
						t_line *tail, char *title);
void				bresenhams_algorithm(t_input *box, t_crd x, t_crd y);
double 				**rot_x(t_input **box, int sign);
double 				**rot_y(t_input **box, int sign);
double 				**rot_z(t_input **box, int sign);
double 				**matrixs_multiplication(double **a, double b[3][3]);
double 				**set_up_base_mtrx(void);
#endif
