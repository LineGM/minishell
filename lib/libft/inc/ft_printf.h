/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_options
{
	char	minus;
	char	null;
	char	hash;
	char	space;
	char	plus;
	int		width;
	int		prec;
	char	type;
}			t_options;

typedef struct s_specs
{
	char			sign;
	unsigned int	value;
	unsigned int	digits;
	unsigned int	field;
	unsigned int	zeros;
	unsigned int	spaces;
}					t_specs;

int		ft_printf(const char *format, ...);

int		get_options(const char *str, int i, va_list args,
			t_options *opts);
int		write_percent(t_options *opts);
int		write_c(va_list args, t_options *opts);
int		write_s(va_list args, t_options *opts);
int		write_d(va_list args, t_options *opts);
t_specs	*get_specs_d(va_list args, t_options *opts);
int		write_u(va_list args, t_options *opts);
int		write_x(va_list args, t_options *opts, char *base);
t_specs	*get_specs_x(va_list args, t_options *opts);
int		write_p(va_list args, t_options *opts);

void	putstr_len(char *str, int len);
void	putchar_n(char c, unsigned int n);
void	putunbr(unsigned int n);
void	putunbr_base(unsigned int n, char *base);
void	putulong_base(unsigned long n, char *base);

#endif