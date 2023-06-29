/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:26:10 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:42:15 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									LSTSIZE
We create two variables: one as a counter and another one that replaces 'lst' 
so as not to modify it. The counter is set to 0, and we loop our new 'lst' until
it reaches null. Inside, it will scroll down the list and add the counter.
On exit, it simply returns the counter.
*/

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*aux;

	size = 0;
	aux = lst;
	while (aux != NULL)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}
