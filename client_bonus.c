/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:04 by danielga          #+#    #+#             */
/*   Updated: 2023/08/02 20:07:16 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

/**
 * @brief Entrará en esta función una vez escriba el mensaje enviado.
 * Únicamente escribirá que el mensaje ha sido correcto.
**/
static void	ft_success(int signal)
{
	if (signal == 1)
	{
		ft_printf("Message Succesfully\n");
	}
}

/**
 * @brief Descompone cada caracter del string recibido en bits y si es 0 lo 
 * envía con la señal SIGUSR1 y si es 1 revisado con AND se envia con SIGUSR2 
 * con la función kill. Cuando haya enviado los 8 bits, moverá al siguiente 
 * caracter del string.
 * 
 * @param pid Es la identificación de la señal del servidor.
 * @param str El string a enviar.
 * 
**/
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

/**
 * @brief Escribirá un mensaje con el PID del servidor para que lo reciba y lo 
 * trascriba. Es necesario que sean tres argumentos para que funcione y el PID 
 * lo pasaremos a enteros.
 * 
 * @param argc Número de argumentos. En este caso son necesarios 3.
 * @param argv Los argumentos recibidos.
 * 
**/
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
	ft_send_bit(pid, "\n");
	ft_success(1);
	return (0);
}
