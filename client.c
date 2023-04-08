/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:14 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/08 02:02:48 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive(int sig)
{
	if (sig == SIGUSR1)
		exit(write(1, "Message received\n", 17));
}

void	transmit(int pid, char *str)
{
	int		i;
	char	j;

	while (*str)
	{
		i = 8;
		j = *str++;
		while (i--)
		{
			if (j >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(400);
	}
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}



int main(int argc, char **argv)
{
	if (argc != 3 || !*argv[2])
		exit(write(1, "Usage: ./client [server PID] [message]\n", 39));
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	transmit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
