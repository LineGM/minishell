/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_d_helper(t_specs *specs, t_options *opts)
{
	if (opts->minus == '0')
		putchar_n(' ', specs->spaces);
	if (specs->sign == '-')
		ft_putchar_fd('-', 1);
	else if (opts->plus == '1')
		ft_putchar_fd('+', 1);
	else if (opts->space == '1')
		ft_putchar_fd(' ', 1);
	putchar_n('0', specs->zeros);
	if (opts->prec != 0 || specs->value != 0)
		putunbr(specs->value);
	if (opts->minus == '1')
		putchar_n(' ', specs->spaces);
	return (specs->field);
}

int	write_d(va_list args, t_options *opts)
{	
	t_specs	*specs;
	int		char_count;

	specs = get_specs_d(args, opts);
	if (specs == NULL)
		return (-1);
	char_count = write_d_helper(specs, opts);
	free(specs);
	return (char_count);
}
