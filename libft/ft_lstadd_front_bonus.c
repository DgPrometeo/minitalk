/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:50:01 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:29:09 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								LSTADD_FRONT
I have simply indicated that the next to 'new' is the pointer to 'lst' since it
points to the first position in the list so that it is placed after 'new', and 
finally, 'lst' which marks the first position, will now be 'new'.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
