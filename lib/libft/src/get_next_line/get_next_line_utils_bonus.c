/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_find_nl(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strlen(char *str)
{
	int	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;
	int		i;

	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	str = malloc(len_s1 + len_s2 + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2 + 1)
	{
		str[i + len_s1] = s2[i];
		i++;
	}
	free(s1);
	return (str);
}

char	*gnl_substr(char *s, int start, int len)
{
	char	*subs;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start >= gnl_strlen(s))
		len = 0;
	subs = malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

void	*gnl_free(char *buffer, t_gnl_list **lst, int fd)
{
	free(buffer);
	lst_free(lst, fd);
	return (NULL);
}
