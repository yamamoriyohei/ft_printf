/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamamor <yyamamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:00:00 by yyamamor          #+#    #+#             */
/*   Updated: 2026/05/09 14:09:00 by yyamamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putHEX(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_putHEX(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

static int	ft_putptr_hex(unsigned long long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int					count;
	unsigned long long	addr;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	count += write(1, "0x", 2);
	count += ft_putptr_hex(addr);
	return (count);
}
