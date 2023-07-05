/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:14:04 by danielga          #+#    #+#             */
/*   Updated: 2023/07/05 13:46:33 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	ft_binary(int pid, char *str)
{
	
}

int	main(int argc, char *argv)
{
	int	pid;

	if (argc != 3)
		exit(EXIT_FAILURE);
	else
		pid = ft_atoi(argv[1]);
		ft_binary(pid, argv[2]);
}

/*
Entiendo que en este programa, va a enviar argumentos al servidor indicando en
el argumento 1 el PDI que da el server.c y el argumento 2 sería la información
que tiene que mostrar el servidor. Esta información según varios compañeros
la mejor forma para que no genere leaks sería enviarlas por byte a byte.
Por ello:
es necesario que sean 3 los elementos a enviar, sino sales con fallo.
Cuando son tres, primero tendremos que indicar el PID
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
-Sleep: 
-Usleep: 
-Exit: 
*/