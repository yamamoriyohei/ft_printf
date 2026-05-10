/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamamor <yyamamor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:55:00 by yyamamor          #+#    #+#             */
/*   Updated: 2026/05/10 18:52:34 by yyamamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[count] != '\0')
	{
		if (ft_putchar(s[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putunbr(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}

int	ft_puthex(unsigned int n)
{
	int		count;
	int		ret;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_puthex(n / 16);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int	count;
	int	ret;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		ret = ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}
