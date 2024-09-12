/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:43:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 21:29:44 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	signal_received(int signal)
{
	// Inicializar las variables estaticas
	static	size_t	i = 0;
	static	size_t byte = 0;
	// Verifica si la señal recbida es SIGUSR1 o SIGUSR2
	if (signal == SIGUSR1)
		byte = byte << 1; // Desplaza el bit a la izquierda y deja el bit en la posicion 0 a 0
	else if (signal == SIGUSR2)
		byte = (byte << 1) | 1; // Desplaza el bit a la izquierda y luego establece la posicion 0 a 1
	i++; // Contador de bits establecidos
	if (i == 8) // Se verifica que la cantidad de bits recibidos sea 8
	{
		ft_printf("%c", (char)byte); // Imprime el character usando los 8 bits para conseguir el numero ascii
		i = 0; // Resetea el contador de bits
		byte = 0; // Resetea el byte para poder seguir acumulando nuevos bits.
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

    // Verificar la cantidad de argumentos
	if (ac != 1 || av[1])
	{
		ft_printf("Please dont put any argument\n");
		return (1);
	}
	// Obtener el PID del proceso actual
	pid = getpid();
	if (pid == -1)
	{
		ft_printf("Error getting pid\n");
		return (1);
	}
	ft_printf("pid: %d\n", pid);
	// Configurar los manejadores de señales
	signal(SIGUSR1, signal_received);
	signal(SIGUSR2, signal_received);
	// Esperar indefinidamente por señales
	while (1)
	{
		pause();
	}
	return (0);
}
/*

  0  1 0  1  1 1 0 1
128/64/32/16/8/4/2/1
s1=0 s2=1

s1 
01011101115
e*/