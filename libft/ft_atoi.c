/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:25 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:12:32 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//									ATOI

/**
 * @brief This function will check if it is a space or any escape route. 
 * 
 * @param a Character to check.
 * 
 * @return If true, it will jump to the next character.
 * @return If false, it will continue the main function.
**/
static int	ft_space(char a)
{
	if (a == ' ' || a == '\f' || a == '\r')
		return (1);
	else if (a == '\n' || a == '\t' || a == '\v')
		return (1);
	return (0);
}

/**
 * @brief This function will check if it is a symbol. 
 * 
 * @param a Character to check.
 * 
 * @return If true, it will change the int to negative "-".
 * @return If false, it will continue the main function.
**/
static int	ft_symbol(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/*
Create 3 variables for the string counter, the integer and the symbol.
We go through spaces, symbols and finally locate the numbers by converting
them to int. Finally, we multiply it by the symbol.
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	nmb;
	int	symbol;

	i = 0;
	nmb = 0;
	symbol = 1;
	if (str[i] == '\0')
		return (0);
	while (ft_space(str[i]) != 0)
		i++;
	if (str[i + 1] == '+' || str[i + 1] == '-')
		return (0);
	while (ft_symbol(str[i]) != 0)
	{
		if (str[i] == '-')
			symbol = -symbol;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nmb = nmb * 10 + (str[i] - '0');
		i++;
	}
	return (symbol * nmb);
}
