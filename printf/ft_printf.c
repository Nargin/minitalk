/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:06:53 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/03 00:28:14 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FLAG "cspdiuxX%"

int	memory_add(unsigned long long int *num, char *base)
{
	int				i;
	int				count;
	unsigned long long int	nbr;
	char			print[16];

	if (!num)
		return (ft_putstr("(nil)"));
	i = 0;
	count = 0;
	nbr = (size_t) num;
	count += ft_putstr("0x");
	while (nbr > 0)
	{
		print[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (i)
		count += ft_putchar(print[--i]);
	return (count);
}

int	test_option(char c)
{
	int	i;

	i = -1;
	while (FLAG[++i])
		if (c == FLAG[i])
			return (1);
	return (0);
}

int	option(char c, va_list params)
{
	if (c == 'c')
		return (ft_putchar(va_arg(params, int)));
	if (c == 's')
		return (ft_putstr(va_arg(params, char *)));
	if (c == 'p')
		return (memory_add(va_arg(params, void *), "0123456789abcdef"));
	if (c == 'd')
		return (ft_nbrbase(va_arg(params, int), "0123456789"));
	if (c == 'i')
		return (ft_nbrbase(va_arg(params, int), "0123456789"));
	if (c == 'u')
		return (u_base((va_arg(params, unsigned int)), "0123456789"));
	if (c == 'x')
		return (u_base(va_arg(params, int), "0123456789abcdef"));
	if (c == 'X')
		return (u_base(va_arg(params, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	params;

	va_start(params, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] && test_option(str[i + 1]))
			count += option(str[i++ + 1], params);
		else
			count += ft_putchar(str[i]);
	}
	return (count);
}
