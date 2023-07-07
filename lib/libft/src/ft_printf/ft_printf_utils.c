/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putulong_base(unsigned long n, char *base)
{
	unsigned long	len_base;

	len_base = ft_strlen(base);
	if (n < len_base)
		ft_putchar_fd(base[n], 1);
	else
	{
		putulong_base(n / len_base, base);
		ft_putchar_fd(base[n % len_base], 1);
	}
}

/*
 * Function that writes an unsigned integer n to the standard output
 * in a specific base.
 */
void	putunbr_base(unsigned int n, char *base)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	if (n < len_base)
		ft_putchar_fd(base[n], 1);
	else
	{
		putunbr_base(n / len_base, base);
		ft_putchar_fd(base[n % len_base], 1);
	}
}

/*
 * Function that writes an unsigned integer n to the standard output.
 */
void	putunbr(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		putunbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
}

/*
 * Function that writes the character c to the standard output n times.
 */
void	putchar_n(char c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

/*
 * Function that writes up to len characters from a string to the
 * standard output.
 */
void	putstr_len(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}
