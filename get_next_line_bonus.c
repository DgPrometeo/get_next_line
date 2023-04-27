/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by danielga          #+#    #+#             */
/*   Updated: 2023/04/27 18:01:26 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(char *str, int fd)
{
	int		r;
	char	*tmp;

	r = 1;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (r > 0 && !ft_strchr(str, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r < 0)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		tmp[r] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

/*
Función para leer el archivo. 

Necesitaremos un entero que sea nuestro valor de lectura para la función READ,
además de crear un puntero para una reserva de memoria temporal tamaño buffer;
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

ahora procedemos a crear un bucle en el que se mantenga mientras tenga algo que 
leer y no sea '\n', en esa posición, cuando la línea se haya formado añadiremos 
el nulo, y posteriormente meteremos eso con un STRJOIN en el buffer original.
Liberamos la reserva de memoria temporal creada y devolvemos el buffer con lo
acumulado.
*/

char	*ft_get_line(char *line)
{
	int		i;
	char	*str;

	if (!line[0])
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char *) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
Esta función cogerá lo leido y los trasladará a la línea para almacenarlo.
Necesitaremos un contador y una reserva de memoria nueva.
Por seguridad verificamos que nos haya dado la línea. Ahora, procedemos a 
localizar donde termina o donde encuentra '\n'. Entonces creamos el malloc
del tamaño de la línea más dos para contar si tiene '\n' y el nulo.
revisamos que se haya creado bien y comenzamos a copiarlo hasta nulo o '\n'
Una vez que se salga del bucle, si ha salido por un '\n' hay que añadirlo también
y se pone la última posición como nulo. Se devuelve la reserva de memoria nueva.
*/

char	*ft_new_line(char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = '\0';
	free(buff);
	return (str);
}

/*
Función para obtener la nueva linea y añadirla a la existente.

Creamos dos enteros para movernos en los strings, y una reserva de memoria.
desplazamos el buffer hasta la posición del nulo o hasta donde haya leído.
si no encuentra esa posición, liberamos la reserva y devolvemos nulo.
Creamos la reserva de memoria con la dimensión del buffer menos lo alcanzado
para recoger lo sobrante más uno para el nulo. Verificamos que se haya creado.
añadimos uno más de i para saltar el nulo.
Y nos metemos en un bucle hasta que alcancemos la posición de i en el buffer.
y procedemos a añadir todo lo de buffer en la nueva reserva de memoria, añadiendo
al final el nulo. 
Liberamos buffer y devolvemos la nueva reserva actualizada.
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = get_read(buffer[fd], fd);
	if (!buffer[fd])
		return (0);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_new_line(buffer[fd]);
	return (line);
}

/*
Creamos una reserva de memoria que recoja la información de lo que vaya a
guardar y no ha leido, para despues seguir leyéndolo que será nuestro buffer. 

Verificamos que nos ha dado un fd válido, ya que sino no debería funcionar.
Además, tenemos que verificar que nos haya dado un BUFFER_SIZE posible,
para que no rompa la función.
Procedemos a leer dandole el almacenaje y el fd. 
si no ha conseguido generar el elemento de lo leido, termina la función.
si todo sale bien, debe de dar lo leído.
Sacamos lo leído del buffer añadiendolo a line.
Una vez teniendo la línea, almacenamos el resto de lo leído en el buffer 
para continuar posteriormente.
*/