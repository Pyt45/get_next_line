/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:23:14 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/16 14:16:53 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_find_line(char *str)
{
	int		i;

	i = -1;
	while (str[++i] && str[i] != '\n')
		;
	return (i);
}

int		ft_handle_err(char **line, char *s, char *buff, int r)
{
	if (r == -1)
	{
		if (*line)
			free(*line);
		if (s)
			free(s);
		if (buff)
			free(buff);
	}
	return (r);
}

char	*ft_strnew(char *str, char *dup)
{
	if (str)
		free(str);
	str = dup;
	return (str);
}

int		ft_check_static(char **s, char **line, int fd)
{
	int		i;
	char	*tmp;

	if (s[fd])
	{
		if (ft_strchr(s[fd], '\n'))
		{
			i = ft_find_line(s[fd]);
			*line = ft_strnew(*line, ft_substr(s[fd], 0, i));
			s[fd] = ft_strnew(s[fd], ft_strdup(s[fd] + i + 1));
			if (!s[fd] || !(*line))
				return (ft_handle_err(line, s[fd], NULL, -1));
			return (1);
		}
		else if (ft_strlen(s[fd]))
		{
			if (!(tmp = (*line) ? ft_strjoin(*line, s[fd]) : ft_strdup(s[fd])))
				return (ft_handle_err(line, s[fd], NULL, -1));
			s[fd] = ft_strnew(s[fd], NULL);
			*line = ft_strnew(*line, tmp);
			return (0);
		}
	}
	free(s[fd]);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *save[FD_SIZE];
	char		*buff;
	char		*tmp;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
	!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*line = ft_strdup("");
	while ((r = read(fd, buff, BUFFER_SIZE)))
	{
		if (r == -1)
			return (ft_handle_err(line, NULL, buff, -1));
		buff[r] = '\0';
		if (!(tmp = (save[fd]) ? ft_strjoin(save[fd], buff) : ft_strdup(buff)))
			return (ft_handle_err(NULL, save[fd], buff, -1));
		save[fd] = ft_strnew(save[fd], tmp);
		free(buff);
		if (ft_strchr(save[fd], '\n'))
			break ;
		if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (ft_handle_err(NULL, save[fd], buff, -1));
	}
	(r == 0) ? free(buff) : 0;
	return (ft_check_static(save, line, fd));
}
