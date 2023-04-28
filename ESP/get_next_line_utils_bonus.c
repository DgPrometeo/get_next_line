/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:34:26 by danielga          #+#    #+#             */
/*   Updated: 2023/04/27 18:24:49 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!s)
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
	if (c == '\0')
		return (&s[ft_strlen(s)]);
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

	if (!buff)
		buff = ft_calloc_bzero(1, 1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] != '\0')
	{
		str[i] = buff[i];
		i++;
	}
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	str[i] = '\0';
	free(buff);
	return (str);
}

/*
Es similar a la función strjoin pero modificando el principio.
Si no existiera buff, como es el caso de la primera vez que accede a la función
tienes que crear un malloc que lo genere ya que al principio se encontrará vacío
y en él tendrá que añadir lo que venga posteriormente.
Hacemos un malloc de la capacidad del buff y del s1 más el nulo.
recorremos primero el buff copiandolo en el nuevo y posteriormente el s1.
despúes liberamos lo que nos habia dado como buffer y devolvemos la actualizada.
*/
