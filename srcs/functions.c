/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:24:10 by alepinoy          #+#    #+#             */
/*   Updated: 2015/01/23 13:24:11 by alepinoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fractol.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = b;
	if (b == NULL)
		return (NULL);
	while (i < (int)len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = dest;
	s2 = src;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (i < (int)n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
