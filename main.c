/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:35:10 by danielga          #+#    #+#             */
/*   Updated: 2023/04/19 17:54:29 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 0;
	line = 0;
	if (argc != 2)
	{
		printf("No has adjuntado un archivo <file>\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error abriendo el archivo");
		return (1);
	}
	line = get_next_line(fd);
	printf("La cadena leída es \"%s\" \n", line);
	line = get_next_line(fd);
	printf("La cadena leída es \"%s\" \n", line);
	line = get_next_line(fd);
	printf("La cadena leída es \"%s\" \n", line);
	/*while (line != NULL || counter == 30)
	{
		printf("La cadena leída es %s\n", line);
		free(line);
		line = get_next_line(fd);
		counter++;
	}*/
	close(fd);
	free(line);
	return (0);
}

/*
fcntl - open/close (para manipular archivos existentes. Para el main.)
stdio - printf

El file descriptor tiene que ser superior a 0 ya que 0 es la entrada estandar??.

Mediante argumentos, abrirá el archivo dado y muestra por pantalla todo lo 
que lea utilizando la funcion "get_next_line". Esta función es llamada desde 
un bucle y las irá imprimiendo y liberando después para no ocupar memoria.
Cuando termine cerrará el archivo con un '0'.

Necesitamos usar las funciones Open y Close. 
OPEN abre un fichero existente retornando un file descriptor:
int open(char *nombre, int modo, int permisos);
el nombre es la cadena conteniendo el nombre del fichero que quier abrir.
el modo establece la forma que se va a trabajar:
- O_RDONLY abre en modo lectura.
- O_WRONLY abre en modo escritura.
- 0_RDWR abre en modo lectura-escritura.
- O_CREAT crea el fichero y lo abre (y si existía destruye el previo).
Esta devolverá un descriptor válido si el fichero ha podido abrirlo, sino -1.

Después tendrás que cerrarlo con la función CLOSE.
int close(int fichero);
el fichero es el descriptor de un fichero abierto. Retorna 0 si va bien.


*/