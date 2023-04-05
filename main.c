/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:35:10 by danielga          #+#    #+#             */
/*   Updated: 2023/04/05 20:45:27 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("No tiene un archivo <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error abriendo el archivo");
		return (1);
	}
	while (line = get_next_line(fd))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}

/*
Mediante argumentos, abrirá el archivo dado y muestra por pantalla todo lo 
que lea utilizando la funcion "get_next_line". Esta función es llamada desde 
un bucle y las irá imprimiendo y liberando después para no ocupar memoria.
Cuando termine cerrará el archivo con un '0'.
*/