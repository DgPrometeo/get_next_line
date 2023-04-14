/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by danielga          #+#    #+#             */
/*   Updated: 2023/04/14 13:19:54 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(char *buffer, int fd)
{
	int		r;
	char	*tmp;

	r = 1;
	tmp = ft_calloc_bzero(BUFFER_SIZE, sizeof(char));
	while (r > 0 && !ft_strchr(buffer, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[r] = '\0';
		buffer = ft_strjoin(buffer, tmp);
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
-Numeros superiores a 0 si ha ido leyendo.
-Si intenta leer el final del archivo devuelve 0. 
-Si fd no es valido devuelve -1 estableciendo "errno" en "EBADF".
-Si el buffer es nulo o mayor al Int_max devolverá -1.

y un string temporal que será para la reserva de memoria de lo que vaya a leer.
ahora procedemos a crear un bucle en el que se mantenga mientras tenga algo que 
leer y no sea '\n', en esa posición, cuando la línea se haya formado añadiremos 
el nulo, y posteriormente meteremos eso con un strjoin en el buffer original.
*/

char	*ft_new_line(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

/*
Función para obtener la nueva linea y añadirla a la existente.

Creamos dos enteros para movernos en los strings, y una reserva de memoria.
desplazamos el buffer hasta la posición del nulo o hasta donde haya leído.
si no encuentra esa posición, liberamos la reserva y devolvemos nulo.
Creamos la reserva de memoria con la dimensión del buffer menos lo alcanzado
más uno para el nulo. Verificamos que se haya creado.
añadimos uno más de i para saltar el nulo.
Y nos metemos en un bucle hasta que alcancemos la posición de i en el buffer.
y procedemos a añadir todo lo de buffer en la nueva reserva de memoria, añadiendo
al final el nulo. 
Liberamos buffer y devolvemos la nueva reserva actualizada.
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0)
		return (0);
	buffer = 0;
	line = get_read(buffer, fd);
	if (!line)
		return (0);
	buffer = ft_new_line(buffer);
	return (line);
}

/*
Creamos una reserva de memoria que recoja la información de lo que vaya a
guardar y no ha leido, para despues seguir leyéndolo que será nuestro buffer. 

Verificamos que nos ha dado un fd válido, ya que sino no debería funcionar.
procedemos a leer dandole el almacenaje y el fd. 
si no ha conseguido generar el elemento de lo leido, termina la función.
si todo sale bien, debe de dar lo leído.
*/