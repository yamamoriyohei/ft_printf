/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamamor <yyamamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:00:00 by yyamamor          #+#    #+#             */
/*   Updated: 2026/05/10 19:28:58 by yyamamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	int		count;
	int		ret;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ret = ft_puthex_upper(n / 16);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (count + 1);
}

static int	ft_putptr_hex(unsigned long long n)
{
	int		count;
	int		ret;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_putptr_hex(n / 16);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	int					count;
	int					ret;
	unsigned long long	addr;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	ret = ft_putptr_hex(addr);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
