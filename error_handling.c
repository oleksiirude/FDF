/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:04 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_manage(int dir, char *title, int ac, int error)
{
	if (ac < 2)
		ft_cprintf("REDCLToo less arguments! GRNCLAborting...STPC\n");
	else if (ac > 2)
		ft_cprintf("REDCLToo many arguments! GRNCLAborting...STPC\n");
	else if (dir > 0)
		ft_cprintf("<REDCL%sSTPC> YELCLis a derictory!"
		"GRNCL Aborting...STPC\n", title);
	else if (error < 0)
		ft_cprintf("REDCLCannot open file. GRNCLAborting...STPC\n");
	return (-1);
}

int		free_and_error_handling(t_line **head)
{
	t_line *tmp;

	while ((*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->line);
		free(tmp);
	}
	ft_cprintf("REDCLInvalid map. GRNCLAborting...STPC\n");
	return (-1);
}
