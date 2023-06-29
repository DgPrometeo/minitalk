/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:39:35 by danielga          #+#    #+#             */
/*   Updated: 2022/12/10 18:37:43 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									BZERO
Create a variable as counter and a char * to control the string. You make a loop
that converts the string to '\0' until n is zero.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	while (n != 0)
	{
		c[i] = '\0';
		i++;
		n--;
	}
}
