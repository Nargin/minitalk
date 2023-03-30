/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:51:10 by romaurel          #+#    #+#             */
/*   Updated: 2023/03/30 17:47:03 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ston(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = -1;
	neg = 1;
	res = 0;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (-1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
		return (ft_printf("Usage: ./client [PID] [message]\n"));
	pid = ston(av[1]);
	if (pid < 0)
		return (ft_printf("Invalid PID\n"));
	kill(pid, SIGUSR1);

}
