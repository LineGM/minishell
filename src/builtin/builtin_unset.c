/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"

int	builtin_unset(int argc __attribute((unused)), char **argv)
{
	int	status;
	int	i;
	int	j;

	status = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && env_is_var_char(argv[i][j]))
			j++;
		if (argv[i][j] != '\0' || argv[i][0] == '\0')
		{
			print_error(SHELL_NAME, "unset", argv[i], "not a valid identifier");
			status = EXIT_FAILURE;
		}
		else
			env_unset_var(argv[i]);
		i++;
	}
	return (status);
}
