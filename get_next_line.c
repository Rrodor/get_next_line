/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:55 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/16 22:52:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_cleanbuf(buf, fd);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*str;
	int	i;

	i = 0;
	fd = open ("toknowyou.txt",	O_RDONLY);
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		i++;
	}
	close (fd);
	return (0);
}
