/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:27 by danielga          #+#    #+#             */
/*   Updated: 2023/07/05 13:34:39 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	ft_signaller(int signal)
{
	
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

/*
Lo primero que hay que hacer en el servidor es optener un ID, para ello utilizas
getpid introduciéndolo en una variable. Imprimimos el comentario especificando 
que es el servidor con el PID usando la función ft_printf y %d.

Ahora tengo que conseguir que pueda recibir las señales de client.c venidas de 
SIGUSR1 y SIGUSR2. Para ellos vamos a usar Signal. Esta función necesita la señal
que va a recoger y una función para procesarlas.
Entonces, para que se mantenga el programa abierto, creamos un bucle que siempre
sea verdad, por lo que va a buscar la primera señal, despues la segunda, y se 
detiene hasta volver a encontrar una señal, o se corte la misma, bajando al 
return.

*/
/*
Funciones permitidas:
-Ft_printf 
-Signal: Permite manejar seales de interrupcion.
-Sigemptyset: para inicializar un conjunto de senales vacio.
-Sigaddset: Agrega una se;al a un conjunto de se;ales.
-Sigaction: sirve para 
-Kill: 
-Getpid: Para obtener el ID del proceso.
-Malloc 
-Free
-Pause: para suspender la ejecucion de un programa
-Sleep: 
-Usleep: 
-Exit: 
*/