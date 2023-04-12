/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:14 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/12 00:34:14 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_wait = 1;

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return (nb * neg);
}

void	confirm(int signal)
{
	if (signal == SIGUSR1)
		g_wait = 1;
	else if (signal == SIGUSR2)
		g_wait = 2;
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_wait = 0;
		if ((c & 0x01 << bit) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(write(1, "Error\n", 6));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(write(1, "Error\n", 6));
		}
		bit++;
		while (1)
		{
			if (g_wait == 1)
				break ;
			else if (g_wait == 2)
				exit(write(1, "MESSAGE sent !\n", 15));
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		exit(write(1, "./client <PID> <STRING>\n", 24));
	if (ft_atoi(av[1]) <= 0)
		exit(write(1, "Wrong PID\n", 10));
	signal(SIGUSR1, confirm);
	signal(SIGUSR2, confirm);
	pid = atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_char(pid, av[2][i++]);
	send_char(pid, '\n');
	send_char(pid, '\0');
	return (0);
}
