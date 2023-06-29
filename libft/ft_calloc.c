/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:53:58 by danielga          #+#    #+#             */
/*   Updated: 2022/12/08 10:53:58 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									CALLOC
We create the variable that will be the memory reservation. We check that it has
been created correctly and if it is ok, we proceed to perform the function 
ft_bzero to empty it.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	else
		ft_bzero(s, count * size);
	return (s);
}
