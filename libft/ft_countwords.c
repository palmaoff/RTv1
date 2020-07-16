/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:00:35 by wquirrel          #+#    #+#             */
/*   Updated: 2020/07/16 19:00:35 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countwords(const char *s, char c)
{
	int i;

	i = 1;
	while (*s && *s == (unsigned char)c)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		i++;
		while (*s == (unsigned char)c)
			s++;
	}
	return (i);
}
