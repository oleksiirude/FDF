/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:29:55 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/02 19:32:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalpha(int c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	if ((c < 65 || c > 90) && (c < 97 || c > 122))
		return (0);
	return (1);
}
