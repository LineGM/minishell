/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(va_list args, t_options *opts)
{
	unsigned char	c;
	int				i;

	c = (unsigned char) va_arg(args, int);
	i = 0;
	if (opts->width <= 1)
		ft_putchar_fd(c, 1);
	else
	{
		if (opts->minus == '1')
			ft_putchar_fd(c, 1);
		while (i < opts->width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if (opts->minus == '0')
			ft_putchar_fd(c, 1);
	}
	return (i + 1);
}
