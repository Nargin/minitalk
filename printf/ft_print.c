/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:23:24 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/03 00:18:22 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strlenbase(char *base)
{
	int	i;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	if (!strlenbase(s))
		return (0);
	count = 0;
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

int	ft_nbrbase(int num, char *base)
{
	int		i;
	int		count;
	char	print[16];

	i = 0;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		if (num == -2147483648)
		{
			print[i++] = base[(2147483648 % strlenbase(base))];
			num /= strlenbase(base);
		}
		num = -num;
	}
	while (num > 0 || i == 0)
	{
		print[i++] = base[num % strlenbase(base)];
		num /= strlenbase(base);
	}
	while (i)
		count += ft_putchar(print[--i]);
	return (count);
}

int	u_base(unsigned int num, char *base)
{
	char	print[16];
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (num > 0 || i == 0)
	{
		print[i++] = base[num % strlenbase(base)];
		num /= strlenbase(base);
	}
	while (i)
		count += ft_putchar(print[--i]);
	return (count);
}
