/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:26:34 by danielga          #+#    #+#             */
/*   Updated: 2022/12/11 14:26:34 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								PUTCHAR_FD
We execute a normal write, but we indicate that the file descriptor will be
given to us beforehand.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
