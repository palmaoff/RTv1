/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:41:19 by eflorean          #+#    #+#             */
/*   Updated: 2019/10/15 16:27:51 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	dup_fr(char **line, char *st)
{
	if (*line != NULL)
		free(*line);
	*line = ft_strdup(st);
}

char	*ft_static(char **line, char st[BUFF_SIZE + 1])
{
	char	*n;
	char	*tmp;

	tmp = NULL;
	n = NULL;
	if (st != NULL)
	{
		if ((n = ft_strchr(st, '\n')))
		{
			*n = '\0';
			dup_fr(line, st);
			ft_strcpy(st, n + 1);
		}
		else
		{
			dup_fr(line, st);
			ft_strclr(st);
		}
	}
	return (n);
}

int		line_maker(int fd, char **line, char st[BUFF_SIZE + 1])
{
	char	buf[BUFF_SIZE + 1];
	int		byte;
	char	*tmp;
	char	*n;

	n = ft_static(line, st);
	while (n == NULL && (byte = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			ft_strcpy(st, ++n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || byte < 0)
			return (-1);
		if (tmp != NULL)
			free(tmp);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return ((ft_strlen(*line) || ft_strlen(st) || byte) ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	int			rt;
	static char	fd_content[OPEN_MAX + 1][BUFF_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strnew(0);
	rt = line_maker(fd, line, fd_content[fd]);
	return (rt);
}
