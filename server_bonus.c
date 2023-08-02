/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:27 by danielga          #+#    #+#             */
/*   Updated: 2023/08/02 20:07:29 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

/**
 * @brief Esta función recibe la señal y la va a recomponer. con un caracter nulo
 * va a ir sustituyendo bit a bit las posiciones donde encuentre que debería de 
 * haber un 1. Si es 0, solo sumará el contador de bits. Una vez tenga los 8 bits
 * de un caracter, lo imprimirá y reseteará el caracter y el número de bits.
 * 
 * @param signal Señal recibida.
**/
static void	ft_signaller(int signal)
{
	static char	str;
	static int	bit;

	if (signal == SIGUSR2)
		str = str | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (str));
		bit = 0;
		str = 0;
	}
}

/**
 * @brief Una vez ejecutado, mostrará el PID del servidorcon el que se podrá 
 * comunicar el cliente gracias a la función getpid. Lo mostrará en pantalla y 
 * se quedará latente a la espera de mensajes. Para recibir las señales 
 * utilizamos la función signal y los SIGURS1 y SIGURS2. Que recorrerá en un 
 * bucle permanente hasta que deje de recibir las señales que son enviadas a 
 * la función ft_signaler.
**/
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
