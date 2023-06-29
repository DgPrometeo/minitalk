/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:06:52 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:25:56 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									LSTADD_BACK
We create a variable in order not to modify lst at the beginning. 
First, we check if in the 'lst' position something exists, if it doesn't, 
that's where we should add the 'new' and end the empty function. If this is not
the case, we run the ft_lstlast function to move to the last position, and in 
the next one we add 'new'.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
}
