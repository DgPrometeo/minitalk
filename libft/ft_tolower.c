/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:05:14 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 18:13:28 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									TOLOWER
If the character is an uppercase, 32 will be reduced to make it a lowercase
character.
*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}
