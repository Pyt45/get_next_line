/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:24:37 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/17 12:52:37 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define FD_SIZE 10240
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

int		get_next_line(int fd, char **line);
int		ft_check_static(char **save, char **line, int fd);
int		ft_find_line(char *str);
int		ft_handle_err(char **line, char *s, char *buff, int r);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strnew(char *str, char *dup);

#endif
