/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:27 by danielga          #+#    #+#             */
/*   Updated: 2023/07/15 22:36:33 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	ft_signaller(int signal)
{
	char	str[];
	int		n;
	int		bit;

	str = "00000000";
	n = 0;
	if (signal == SIGUSR1)
		bit = 0;
	else if (signal == SIGUSR2)
		bit = 1;
	else
		exit(EXIT_FAILURE);
	ft_printf("%s\n", str);
	str += bit << n++;
	ft_printf("%s\n", str);
	ft_printf("%s\n", n);
	if (n == 7)
	{
		ft_printf("%c", str);
		if (str == '\0')
			ft_printf("\n");
		n = 0;
		str = 0;
	}
}

/*
Esta función recibirá las señales y las reproducirá. 
tenemos el string que reproducirá caracter a caracter.
el int bit que se establecerá si es 1 o 0.
y el int n para las posiciones del 0 al 7 de un bits.

Cuando tenga todos los bit del carácter lo imprimirá,
y cuando el string sea nulo, terminará con un salto de línea.
*/

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, ft_signaller);
	signal(SIGUSR2, ft_signaller);
	while (1)
	{
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
-Write
-Ft_printf 
-Signal: Permite manejar seales de interrupcion.
-Sigemptyset: para inicializar un conjunto de senales vacio.
-Sigaddset: Agrega una se;al a un conjunto de se;ales.
-Sigaction: sirve para 
-Kill: para enviar las señales al server.
-Getpid: Para obtener el ID del proceso.
-Malloc 
-Free
-Pause: para suspender la ejecucion de un programa
-Sleep: suspende la ejecución de un programa en una serie de segundos concretos.
-Usleep: suspende la ejecución de un programa en una serie de microsegundos.
-Exit: finalizará la ejecución del programa completamente para volver el sistema
operativo.
*/