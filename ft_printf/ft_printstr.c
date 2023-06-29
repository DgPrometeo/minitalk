/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:46 by danielga          #+#    #+#             */
/*   Updated: 2023/01/18 20:19:48 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[i] != '\0')
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}
