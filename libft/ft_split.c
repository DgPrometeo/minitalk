/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:14:27 by danielga          #+#    #+#             */
/*   Updated: 2022/12/13 16:14:27 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//									SPLIT
/**
 * @brief This function runs through the string counting how many sections the 
 * memory pool must have to hold the string in memory. memory cache has to have 
 * in order to hold the string in memory.
 * 
 * @param s The original string.
 * @param c The delimiting character
 * 
 * @return The number of cells the memory will have.
 **/
static size_t	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			w++;
		}
		else
			i++;
	}
	return (w);
}

/**
 * @brief This function will traverse the string until it reaches the delimiter
 * or null. It will start at the position of the pointer you give it to count 
 * each section independently.
 * 
 * @param s The original string.
 * @param c The delimiting character
 * 
 * @return The dimension that each memory cell will have to occupy.
**/
static size_t	ft_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
				len++;
				s++;
	}
	return (len);
}

/**
 * @brief This function runs through and frees each memory cell, ending with 
 * the freeing of the large memory cache.
 * 
 * @param str The complete memory.
 * 
 * @return Nothing, as it destroys the memory cache.
**/
static void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/**
 * @brief This function will traverse the string and when it reaches each 
 * element, it calculates its dimension and we move the string to that 
 * position to speed it up. At the memory location we run an ft_substr to 
 * insert the corresponding string into the memory cell. We check if it has
 * been saved correctly and  we continue until we write the last cell where
 * a NULL character was inserted.
 * 
 * @param str The memory reserve.
 * @param s The original string.
 * @param c The delimiting character
 * 
 * @return The dimension that each memory cell will have to occupy.
**/
static char	**ft_make_cells(char **str, char *s, char c)
{
	size_t	len;
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = ft_len(s, c);
			s = s + len;
			str[n] = ft_substr(s - len, 0, len);
			if (str[n] == NULL)
			{
				ft_free(str);
				return (NULL);
			}
			n++;
		}
		else
			s++;
	}
	str[n] = NULL;
	return (str);
}

/*
We create the memory pool of type char **. Its size shall be char * and 
the number of fragments it has calculated with the ft_wordcounter function
plus 1 to consider the last cell to be null. 
We check that it has been created correctly or we have been given the 
string, otherwise it would be null. 
Once everything is correct, in the return the main function will start 
to fill each cell with its corresponding substring.
*/

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * (ft_wordcounter(s, c) + 1));
	if (!str || !s)
		return (NULL);
	return (ft_make_cells(str, (char *)s, c));
}
