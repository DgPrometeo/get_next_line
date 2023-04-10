/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:58:01 by danielga          #+#    #+#             */
/*   Updated: 2023/04/10 19:25:34 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_read(char *buffer, int fd);
size_t	ft_strlen(char *str);
char	*ft_calloc_bzero(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *buff, char *s2);

#endif

/*
unistd - Read - write
stdlib - malloc/free

BUFFER_SIZE es la cantidad de bytes que leera de golpe.
*/