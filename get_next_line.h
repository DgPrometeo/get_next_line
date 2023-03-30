/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:58:01 by danielga          #+#    #+#             */
/*   Updated: 2023/03/30 16:39:03 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFED_SIZE
#  define BUFFED_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif

/*
fcntl - open/close (para manipular archivos existentes. Para el main.)
stdio - printf (No se puede usar pero para el main)
unistd - Read - write
stdlib - malloc/free

*/