/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:41:37 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 17:44:50 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

int	sendsignal(int pid, char *string)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (string[i] != '\0')
	{
		while (bit <= 7)
		{
			if (string[i] & (1 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
		}
		bit = 0;
		i++;
	}
	return (0);
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
	if (pid)
		sendsignal(pid, av[2]);
	return (0);
}
/* 
  0  1  1  0 0 0 0 1
128/64/32/16/8/4/2/1

97 en ascii 'a' | en binario
*/