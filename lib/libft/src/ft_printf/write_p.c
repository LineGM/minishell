/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putaddr(unsigned long n, t_options *opts)
{
	putstr_len("0x", 2);
	if (n != 0 || opts->prec != 0)
		putulong_base(n, "0123456789abcdef");
}

static int	get_digits_p(unsigned long n)
{
	if (n < 16)
		return (3);
	return (get_digits_p(n / 16) + 1);
}

int	write_p(va_list args, t_options *opts)
{
	unsigned long	p;
	int				len;
	int				i;

	p = (unsigned long) va_arg(args, void *);
	if (p == 0 && opts->prec == 0)
		len = 2;
	else
		len = get_digits_p(p);
	i = 0;
	if (opts->width <= len)
		putaddr(p, opts);
	else
	{
		if (opts->minus == '1')
			putaddr(p, opts);
		while (i < opts->width - len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if (opts->minus == '0')
			putaddr(p, opts);
	}
	return (len + i);
}
