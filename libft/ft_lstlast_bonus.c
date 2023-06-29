/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:45:21 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:37:21 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									LSTLAST
We create a variable to go through 'lst' without having to modify 'lst', and we
put a loop in which it will check if the next one is NULL, to return that 
position; or if not it will keep adding position, and, it will continue adding 
positions until it reaches the end where it returns the last position.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		if (aux->next == NULL)
			return (aux);
		aux = aux->next;
	}
	return (aux);
}
