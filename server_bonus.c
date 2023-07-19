/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:35:21 by danielga          #+#    #+#             */
/*   Updated: 2023/07/19 12:36:40 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	ft_signaller(int signal)
{
	static char	str;
	static int	bit;

	if (signal == SIGUSR2)
	{
		str = str | (1 << (7 - bit));
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (str));
		bit = 0;
		str = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_signaller);
		signal(SIGUSR2, ft_signaller);
		pause();
	}
	return (0);
}
