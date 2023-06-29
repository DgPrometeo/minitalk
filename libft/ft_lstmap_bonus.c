/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:30:27 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:37:39 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									LSTMAP
We create two variables: one for the new list and another one for each node. 
if we have been given all the elements of the function, the 'new' we mark it 
as null so that it is empty. We work inside a loop in which we create the new 
node with the function 'f' executed in the content. We check if it has been 
created, because if it has not worked, we execute 'lstclear' to remove it 
with 'del'. If it works correctly, we add it in the last position of the 'new'
list, that is to say, where the NULL is, so in the first step it would be in 
the first position and in the following ones. If it has not been done, run 
'lstclear' again. and to exit the loop, we go forward in the list until it 
is complete.
*/

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (!lst || !f || !del)
		return (0);
	new = NULL;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (!aux)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, aux);
		if (!ft_lstlast(new))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
