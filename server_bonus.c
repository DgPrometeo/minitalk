/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:27 by danielga          #+#    #+#             */
/*   Updated: 2023/08/09 18:53:40 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

/**
 * @brief Esta función recibe la señal y la va a recomponer. con un caracter nulo
 * va a ir sustituyendo bit a bit las posiciones donde encuentre que debería de 
 * haber un 1. Si es 0, solo sumará el contador de bits. Una vez tenga los 8 bits
 * de un caracter, lo imprimirá y reseteará el caracter y el número de bits.
 * 
 * @param signal Señal recibida.
 * @param info Toda la información de la señal.
 * @param context En este caso no lo utilizamos (void).
 * 
**/
static void	ft_signaller(int signal, siginfo_t *info, void *context)
{
	static char	caracter;
	static int	bit;

	(void) context;
	if (signal == SIGUSR2)
		caracter = caracter | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (caracter));
		bit = 0;
		caracter = 0;
		kill(info->si_pid, SIGUSR1);
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
	int					pid;
	struct sigaction	info;

	pid = getpid();
	ft_printf("PID SERVER: %d\n", pid);
	info.sa_sigaction = ft_signaller;
	sigemptyset(&info.sa_mask);
	info.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &info, NULL);
		sigaction(SIGUSR2, &info, NULL);
		pause();
	}
	return (0);
}
