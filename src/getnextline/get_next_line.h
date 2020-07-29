/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:43:00 by eflorean          #+#    #+#             */
/*   Updated: 2020/07/29 21:26:14 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPEN_MAX 1024
# define BUFF_SIZE 16
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

int				get_next_line(const int fd, char **line);

#endif
