/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:04 by danielga          #+#    #+#             */
/*   Updated: 2023/07/17 13:55:56 by danielga         ###   ########.fr       */
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
			usleep(1000);
		}
		str++;
	}
}
/*
Hará un bicle mientras haya str. en el indicará que un bit son 8
entonces el elemento que hemos creado de caracter es igual a donde se encuentra
el puntero str. ese caracter lo vamos a descomponer en los 8 bits enviando
con el kill cuando sea 0 con el SIGUSR1 y si verifica que es al recorrer 
el bit es un 1 con AND "&" enviara la SIGUSR2. descansa 1000 microsegundos
y vuelve reduciendo un bit. 
*/

/*static void	ft_send_bit(int pid, char *str)
{
	int		bit;
	char	character;

	while (*str)
	{
		bit = 8;
		character = *str++;
		while (bit--)
		{
			if (character >> bit & 1)
				kill (pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
	}
}*/

/*static void	ft_binary(int pid, char *str, int len)
{
	int	i;
	int	position;

	while (*str)
	{
		position = 0;
		while (position <= 7)
		{
			if (str[i] >> position & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			position++;
			usleep(3000);
		}
		i++;
	}
}*/
/*
Aquí entra el pid, el string que realmente es el binario y la dimensión.
En lo escrito hay dos opciones (o 0 o 1) vamos a usar los dos canales 
para ello, y la función KILL para enviar la señal del proceso. tenemos 
un contador que llegará hasta 7 para poco a poco llegar a la última posición
del bits que es el 0. Si la posicion i del string movido a la derecha 
equivale a 1 se enviará 1 con kill.
si no es el caso, se enviara con el 0. 
Sumamos una posición del string para ver los siguientes bits.
cuando llegue a los 8 bits, se sumará una posición del string.
*/

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		exit(EXIT_FAILURE);
	else
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
	//	ft_binary(pid, argv[2], ft_strlen(str));
		ft_send_bit(pid, str);
	}
	return (0);
}

/*
Entiendo que en este programa, va a enviar argumentos al servidor indicando en
el argumento 1 el PDI que da el server.c y el argumento 2 sería la información
que tiene que mostrar el servidor. Esta información según varios compañeros
la mejor forma para que no genere leaks sería enviarlas por byte a byte.
Por ello:
es necesario que sean 3 los elementos a enviar, sino sales con fallo.
Cuando son tres, primero tendremos que indicar el PID, que lo hacemos entero 
con ATOI, después la información dada tiene que enviarse de manera binaria,
para que tenga una recepción el servidor sin leaks.
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