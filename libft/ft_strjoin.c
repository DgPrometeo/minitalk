/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:20:36 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 10:21:37 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								STRJOIN
We verify that we have been given the two strings to start the function, if not, 
it will give 0. We will need two counters (one for each string) and the memory 
reserve. We create the memory reserve of type char, with the dimensions of the 
sum of each string calculated with the function 'ft_strlen' +1 to add the null. 
We checked that it has been generated correctly and we proceed with a loop to 
introduce in the memory reserve the 's1' with the first counter. Once we have 
reached the null of the first string, we introduce in the following loop the 
second string with the new counter, while the previous counter is the one that 
maintains the memory reserve. Once we have reached the last position of the 
string 2, we place the null in the next position. 
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
