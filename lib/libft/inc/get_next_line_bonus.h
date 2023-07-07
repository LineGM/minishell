/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_list
{
	int					fd;
	char				*stat;
	struct s_gnl_list	*next;
}						t_gnl_list;

char		*ft_get_next_line(int fd);
char		*get_line(t_gnl_list **lst, int fd);
t_gnl_list	*lst_new(int fd);
t_gnl_list	*lst_foc(t_gnl_list **lst, int fd);
void		lst_free(t_gnl_list **lst, int fd);

int			gnl_find_nl(char *str);
int			gnl_strlen(char *str);
char		*gnl_strjoin(char *s1, char *s2);
char		*gnl_substr(char *s, int start, int len);
void		*gnl_free(char *buffer, t_gnl_list **lst, int fd);

#endif
