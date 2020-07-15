/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:33:27 by wquirrel          #+#    #+#             */
/*   Updated: 2019/10/08 20:36:44 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../libft/libft.h"
# define BUFF_SIZE 10

typedef struct	s_file
{
	char			*str;
	int				fd;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
