/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:58:01 by danielga          #+#    #+#             */
/*   Updated: 2023/04/05 20:28:40 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_read(char *buffer, int fd);
size_t	ft_strlen(char *str);
char	*ft_calloc_bzero(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *buff, char *s2);

#endif

/*
fcntl - open/close (para manipular archivos existentes. Para el main.)
stdio - printf (No se puede usar pero para el main)
unistd - Read - write
stdlib - malloc/free

*/