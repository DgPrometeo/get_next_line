/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by danielga          #+#    #+#             */
/*   Updated: 2023/04/28 16:52:00 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Function to read the file. 
We will need an integer to be our read value for the READ function, in addition
to creating a pointer to a temporary memory buffer size;
READ returns the number of bytes read. It must be less than buffer_size.
ssize_t read (int fd, void *buf, size_t count): 
-fd: the file descriptor to read.
-buf: a pointer taken from the memory where the read is stored.
-count: the size of characters/bytes to read.
Returns:
-numbers greater than 0 if it has been reading.
-If it tries to read the end of the file it returns 0. 
-If fd is not valid it returns -1 setting "errno" to "EBADF".
-If the buffer is null or greater than Int_max it will return -1.
now we proceed to create a loop in which it will keep looping for as long as it
has something to  and it is not '\n', in that position, when the line has been
formed we will add the null, and later we will put the  the null, and later we
will put that with a STRJOIN in the original buffer.
We liberate the temporary memory reserve created and we return the buffer with
the accumulated.
*/

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
This function will take the readings and move them to the line to 
store them. We will need a counter and a new memory reservation.
For security we verify that it has given us the line. Now, we proceed to locate
where it ends or where it finds '\n'. Then we create the malloc of the size of 
the line plus two to count if it has '\n' and the null.
We check that it has been created correctly and start copying it to null or '\n'.
Once out of the loop, if it has been exited by a '\n' we have to add it also and 
set the last position as null. The new memory pool is returned.
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
Function to obtain the new line and add it to the existing one.

We create two integers to move in the strings, and a memory buffer.
we move the buffer to the null position or as far as it has read.
If it does not find that position, we free the buffer and return null.
We create the memory pool with the size of the buffer minus what is reached to 
pick up the overflow plus one to pick up the overflow.
to pick up the remainder plus one for the null. We verify that it has been 
created. We add one more of i to skip the null.
And we get into a loop until we reach the position of i in the buffer.
and proceed to add everything from the buffer into the new memory pool, adding 
the null at the end. 
We free buffer and return the new updated pool.
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
We create a memory reserve that collects the information of what is 
going to be saved and has not been and it has not read, to continue 
reading it later that will be our buffer. 

We verify that it has given us a valid fd, otherwise it should not work.
In addition, we have to verify that it has given us a possible BUFFER_SIZE,
so that it does not break the function.
We proceed to read by giving it the storage and the fd. 
If it has not managed to generate the element of the read, it terminates
the function. if everything goes well, it should give the read.
We remove the read from the buffer by adding it to line.
Once we have the line, we store the remainder of the read in the buffer 
to continue later.
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_read(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (0);
	}
	line = ft_get_line(buffer);
	buffer = ft_new_line(buffer);
	return (line);
}
