/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:35:10 by danielga          #+#    #+#             */
/*   Updated: 2023/07/19 13:10:17 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	ft_send_bit(int pid, char *str)
{
	int		bit;
	char	character;

	while (*str)
	{
		bit = 8;
		character = *str;
		while (bit--)
		{
			if (character >> bit & 1)
				kill (pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments. Need ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_send_bit(pid, str);
	}
	return (0);
}
