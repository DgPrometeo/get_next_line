/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by danielga          #+#    #+#             */
/*   Updated: 2023/04/05 20:52:15 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(char *buffer, int fd)
{
	int		r;
	char	*tmp;

	r = 1;
	tmp = ft_calloc_bzero(BUFFER_SIZE, sizeof(char));
	while (r > 0)
	{
		r = read(fd, tmp, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(tmp);
	return (buffer);
}

/*
Función para leer el archivo. 

necesitaremos un entero que sea nuestro valor de lectura para la función READ;
READ devuelve el numero de bytes leidos. tiene que ser menor que buffer_size.
ssize_t read (int fd, void *buf, size_t count): 
-fd: el file descriptor que leerá.
-buf: un puntero tomado de la memoria donde se encuentra almacenado la lectura.
-count: el tamaño de caracteres/bytes a leer.
Devuelve:
-Si intenta leer el final del archivo devuelve 0. 
-Si fd no es valido devuelve -1 estableciendo "errno" en "EBADF".
-Si el buffer es nulo o mayor al Int_max devolverá -1.

y un string temporal que 
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	buffer = 0;
	line = get_read(buffer, fd);
	return (line);
}

/*
Creamos una reserva de memoria que recoja la información de lo que vaya a
guardar y no ha leido, para despues seguir leyéndolo. 

Si lee la función debe de dar un número superior a 0 para poder continuar.

Finalmente, la línea se habrá formado, por lo que añadimos en la posición
saliente el nulo y devolvemos la línea leída.
*/