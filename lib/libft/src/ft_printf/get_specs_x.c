/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specs_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_spaces_x(t_specs *specs, t_options *opts)
{
	unsigned int	spaces;

	spaces = specs->field - specs->digits - specs->zeros;
	if (opts->hash == '1' && specs->value != 0)
		spaces -= 2;
	return (spaces);
}

static unsigned int	get_zeros_x(t_specs *specs, t_options *opts)
{
	unsigned int	zeros;

	zeros = 0;
	if (opts->prec != -1 && (unsigned int) opts->prec > specs->digits)
		zeros = opts->prec - specs->digits;
	else if (opts->prec == -1)
	{
		if (opts->null == '1' && opts->minus == '0')
		{
			zeros = specs->field - specs->digits;
			if (opts->hash == '1' && specs->value != 0)
				zeros -= 2;
		}
	}
	return (zeros);
}

static unsigned int	get_field_x(t_specs *specs, t_options *opts)
{
	unsigned int	field;
	unsigned int	prec;

	field = specs->digits;
	if (opts->hash == '1' && specs->value != 0)
		field += 2;
	if (opts->width != -1 && (unsigned int) opts->width > field)
		field = opts->width;
	if (opts->prec != -1)
	{
		prec = opts->prec;
		if (opts->hash == '1' && specs->value != 0)
			prec += 2;
		if (prec > field)
			field = prec;
	}
	return (field);
}

static unsigned int	get_digits_x(unsigned int n)
{
	if (n < 16)
		return (1);
	return (get_digits_x(n / 16) + 1);
}

t_specs	*get_specs_x(va_list args, t_options *opts)
{
	t_specs			*specs;
	unsigned int	x;

	specs = malloc(sizeof(t_specs));
	if (specs == NULL)
		return (NULL);
	x = (unsigned int) va_arg(args, unsigned int);
	specs->sign = 'x';
	specs->value = x;
	if (specs->value == 0 && opts->prec == 0)
		specs->digits = 0;
	else
		specs->digits = get_digits_x(specs->value);
	specs->field = get_field_x(specs, opts);
	specs->zeros = get_zeros_x(specs, opts);
	specs->spaces = get_spaces_x(specs, opts);
	return (specs);
}
