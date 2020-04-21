/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:49:39 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/12 17:56:58 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
		{
			c = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (c);
		}
		else
			i++;
	}
	c = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (c);
}
