/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:09:25 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 18:11:59 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								SUBSTR
First we check if we have a string. If there is no 's', I return null.
Next, we have to check if the size of the string is smaller than the start 
location. If it is, we must create an empty memory, since we cannot add any 
elements of the string.
If (the size of the string - the position of the 'start') is "<" the maximum 
length of the substring, we have to modify the 'len' so that it can cover that
information and not be larger and add more elements than necessary.
Once these possibilities are established, we create the malloc with the 
dimension of the len +1 to occupy the necessary plus the null. We check that
it has been created and use the function 'ft_memcpy' to copy into memory, the
string at the 'start' position to the 'len'. Finally returning the memory.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
