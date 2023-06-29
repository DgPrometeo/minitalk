/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:31:46 by danielga          #+#    #+#             */
/*   Updated: 2022/12/11 14:31:46 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								PUTENDL_FD
We execute write, but we indicate that the file descriptor will be
given to us beforehand. Then, we put the string and run 'ft_strlen' to know 
the total dimension of the string. Next, we write the line break.
*/

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
