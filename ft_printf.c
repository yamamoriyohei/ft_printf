/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamamor <yyamamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:30:00 by yyamamor          #+#    #+#             */
/*   Updated: 2026/05/09 14:09:00 by yyamamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (format[i + 1] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == '%')
				count += ft_putchar('%');
			else if (format[i + 1] == 'p')
				count += ft_putptr(va_arg(args, void *));
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (format[i + 1] == 'u')
				count += ft_putunbr(va_arg(args, unsigned int));
			else if (format[i + 1] == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
			else if (format[i + 1] == 'X')
				count += ft_putHEX(va_arg(args, unsigned int));
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
