/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:34:26 by danielga          #+#    #+#             */
/*   Updated: 2023/04/14 13:28:02 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	i++;
	return (i);
}

char	*ft_calloc_bzero(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(count * size + 1);
	if (s == NULL)
		return (NULL);
	else
	{
		while (size != 0)
		{
			s[i] = '\0';
			i++;
			size--;
		}
	}
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	char	x;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	x = (char) c;
	while (s[i] != x)
	{	
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (&s[i]);
}

char	*ft_strjoin(char *buff, char *s1)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!buff && !s1)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		str[i] = buff[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
