/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:19:44 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:34:53 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									LSTITER
We create a loop that goes through the whole list, and inside it we execute
the function 'f' on each content of each node. Then we move it to the next 
node with next.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
