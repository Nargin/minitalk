/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <rxonrgn@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:12 by romaurel          #+#    #+#             */
/*   Updated: 2023/04/08 01:58:01 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str = NULL;

void	putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*update(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(str);
	return (tmp);
}

void	ft_get_sig(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	bit = 0;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		g_str = update(g_str, i);
		if (i == '\0')
		{
			write(1, g_str, ft_strlen(g_str));
			g_str[0] = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
			kill(info->si_pid, SIGUSR1);
		i = 0;
		bit = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	g_str = malloc(1);
	g_str[0] = 0;
	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_get_sig;
	write(1, "Server PID: ", 12);
	putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
