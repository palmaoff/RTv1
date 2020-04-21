/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:17:11 by wquirrel          #+#    #+#             */
/*   Updated: 2019/10/08 20:24:38 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_linenew(char **string, char **line)
{
	int		len;
	char	*str;

	len = 0;
	while (*string && (*string)[len] != '\n')
		len++;
	if (!(*line = ft_strsub(*string, 0, len)))
		return (-1);
	if (!(str = ft_strsub(*string, len + 1, ft_strlen(*string))))
		return (-1);
	free(*string);
	if (!(*string = ft_strdup(str)))
	{
		free(str);
		return (-1);
	}
	free(str);
	return (1);
}

static t_file	*ft_lstnewfd(int fd)
{
	t_file *list;

	if (!(list = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(list->str = ft_strnew(0)))
	{
		free(list);
		return (NULL);
	}
	list->fd = fd;
	list->next = NULL;
	return (list);
}

static t_file	*ft_find_fd(t_file **head, int fd)
{
	t_file *file;

	if (!*head)
		*head = ft_lstnewfd(fd);
	file = *head;
	while (file->fd != fd && file->next)
		file = file->next;
	if (file->fd == fd)
		return (file);
	else
		return (file->next = ft_lstnewfd(fd));
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*head = NULL;
	t_file			*f;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			size;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line ||
	!(f = ft_find_fd(&head, fd)))
		return (-1);
	while (!f->str || !ft_strchr(f->str, '\n'))
	{
		if (!(size = read(fd, buff, BUFF_SIZE)))
		{
			if (!(*line = f->str) || *f->str == '\0')
				return (0);
			f->str = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = f->str;
		f->str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (ft_linenew(&f->str, line));
}
