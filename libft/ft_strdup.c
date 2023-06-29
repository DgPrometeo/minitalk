/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:42:47 by danielga          #+#    #+#             */
/*   Updated: 2022/12/09 00:42:47 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRDUP
We create a counter, a 'char *' to be the memory pool, and an integer to know 
the dimension of the given string with the function 'ft_strlen'. We create the 
memory with the dimension obtained with the previous function + 1 to add the 
null. Once we have verified that it has been generated correctly, we proceed 
to add each position of the string inside the memory reserve, placing the null
in the last position.
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (str == NULL)
		return (0);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
