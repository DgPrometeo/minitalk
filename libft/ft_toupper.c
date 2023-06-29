/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:57:52 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 18:14:35 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								TOUPPER
If the character is an lowercase, 32 will be added to make it a uppercase
character.
*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}
