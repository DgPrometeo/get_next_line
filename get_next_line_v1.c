/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by danielga          #+#    #+#             */
/*   Updated: 2023/04/05 21:01:50 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	int		r;

	i = 0;
	r = 0;
	line = malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	while ((r = read(fd, &line[i], 1)) > 0)
	{
		if (line[i] == '\n')
			break;
		i++;
	}
	if (r == 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

/*
Creamos una reserva de memoria que recoja la información de lo que vaya a
guardar y no ha leido, para despues seguir leyéndolo. 

Si lee la función debe de dar un número superior a 0 para poder continuar.

READ devuelve el numero de bytes leidos. tiene que ser menor que buffer_size.
ssize_t read (int fd, void *buf, size_t count): 
-fd: el file descriptor que leerá.
-buf: un puntero tomado de la memoria donde se encuentra almacenado la lectura.
-count: el tamaño de caracteres/bytes a leer.
Devuelve:
-Si intenta leer el final del archivo devuelve 0. 
-Si fd no es valido devuelve -1 estableciendo "errno" en "EBADF".
-Si el buffer es nulo o mayor al Int_max devolverá -1.

Finalmente, la línea se habrá formado, por lo que añadimos en la posición
saliente el nulo y devolvemos la línea leída.

*/