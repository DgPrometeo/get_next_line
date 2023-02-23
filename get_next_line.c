/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by danielga          #+#    #+#             */
/*   Updated: 2023/02/23 13:40:16 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
