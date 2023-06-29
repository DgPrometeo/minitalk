/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:20:00 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 18:08:26 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								STRTRIM
We create the counter variable and another one to count the end (with 'ft_strlen'
function). First I check that I have the two elements given in the function, if 
any of them is missing, it will give null.
I create a loop in which the counter will stop when it finds, thanks to the 
function 'ft_strchr', the difference between the string and 'set'.
Then, I find again the difference with the function 'ft_strrchr' from the end.
And finally I return the function 'ft_substr' to create a memory reservation 
with malloc created with the string that I have to be modified. The initial 
position is where the counter that started at 0 was and the dimension will be 
the counter that started from the end subtracted the initial counter +1 to 
consider the null space.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fin;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	fin = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (fin > i && ft_strrchr(set, s1[fin]))
		fin--;
	return (ft_substr(s1, i, fin - i + 1));
}
