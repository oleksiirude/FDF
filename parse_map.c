/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	skip_hex(char **line)
{
	(*line)++;
	while (ft_strchr("AaBbCcDcEeFf0x987654321", **line) && **line)
		(*line)++;
	if (**line != ' ' && **line)
		return (0);
	if (**line != ' ' && !**line)
		return (1);
	if (**line == ' ')
		return (1);
	return (0);
}

int	parse_line(char *line, int *x)
{
	int counter;

	counter = 0;
	while (*line)
	{
		if (*line == '-' || *line == '+')
			line++;
		if (!ft_isdigit(*line))
			return (0);
		atoi_ptr(&line);
		counter++;
		if (*line == ',')
			if (!skip_hex(&line))
				return (0);
		if (*line == ' ')
			while (*line == ' ' && *line)
				line++;
	}
	if (!*x)
		*x = counter;
	else
		if (*x != counter)
			return (0);
	return (1);
}


int parse_map(t_line **lst, int fd, char *title)
{
	int		x;
	int		counter;
	char	*line;

	x = 0;
	counter = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (parse_line(line, &x))
		{
			(*lst)->row = line;
			(*lst)->y = counter++;
			(*lst)->next = (t_line*)malloc(sizeof(t_line));
			*lst = (*lst)->next;
			(*lst)->next = NULL;
		}
		else
			return (free_line(&line));
	}
	return (1);
}