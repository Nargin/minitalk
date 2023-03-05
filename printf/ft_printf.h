/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:21:11 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/02 23:40:22 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	strlenbase(char *base);

int	ft_nbrbase(int num, char *base);

int	option(char c, va_list params);

int	ft_printf(const char *str, ...);

int	u_base(unsigned int num, char *base);

int	memory_add(unsigned long long int *num, char *base);

#endif
