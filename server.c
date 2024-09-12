/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:43:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 18:05:59 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	signal_received(int signal)
{
	int i;
	int bit;

	i = 0;
	bit = 0;
	if (signal == SIGUSR1)
		bit = bit << 1;
	if (signal == SIGUSR2)
		bit = 
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 1)
	{
		ft_printf("Please put only one argument\n");
		return (1);
	}
	while (1)
	{
		pid = getpid();
		if (pid == 0)
			return (1);
		ft_printf("pid: %d\n", pid);
		pause();
	}
	signal(SIGUSR1, signal_received);
	signal(SIGUSR2, signal_received);
	return (0);
}
/*

  0  1 0  1  1 1 0 1
128/64/32/16/8/4/2/1
s1=0 s2=1

s1 
01011101115
e*/