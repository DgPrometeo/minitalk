/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:28:49 by danielga          #+#    #+#             */
/*   Updated: 2022/12/11 14:28:49 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								PUTSTR_FD
We execute write, but we indicate that the file descriptor will be
given to us beforehand. Then, we put the string and run 'ft_strlen' to know 
the total dimension of the string.
*/

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
