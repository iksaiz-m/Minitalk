/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:41:37 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 21:14:06 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	sendsignal(int pid, char *string)
{
	int	i;
	int	bit;
	
	i = 0;
	bit = 8;
	while (string[i] != '\0')
	{
		bit = 8;
		while (--bit >= 0) // Numero de posiciones que se desplazaran los bits a la derecha
		{
			if (((string[i] >> bit) & 1)) //Desplaza el bit a la derecha hasta la posicion 0 y verifica si el bit es 1
				kill(pid, SIGUSR2); // En caso de ser cierto se envia SIGUSR2 valor bit = 1
			else
				kill(pid, SIGUSR1); //Si no es cierto se envia SIGUSR1 valor bit = 0
			usleep(100); // espera 100 microsegundos para darle tiempo a procesar al servidor
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Please put the server pid and the sending String\n");
		return (1);
	}
	else
		pid = ft_atoi(av[1]);
	if (pid == 0)
		return (1);
	if (pid )
		sendsignal(pid, av[2]);
	return (0);
}
/* 
  0  1  1  0 0 0 0 1
128/64/32/16/8/4/2/1

97 en ascii 'a' | en binario
*/