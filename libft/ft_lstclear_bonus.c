/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:05:09 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:32:34 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									LSTCLEAR
Create an auxiliary variable to be the pointer to 'lst'. We create a loop that
goes through the whole list and in it, we indicate that the 'aux' is the next
one in the list and we call the function 'ft_lstdelone' to delete and free it.
And we indicate that the pointer of 'lst' is the new empty 'aux'.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = aux;
	}
}
