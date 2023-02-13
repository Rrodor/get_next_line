/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:35:55 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/13 20:15:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	l;
	char	*buf;
	char	t;
	int	i;

	i = 0;
	buf = malloc((ft_linesize(fd) + 1) * sizeof(char));
	l = read(fd, &t, 1);
	while (t != '\n' && l)
	{
		buf[i] = t;
		l = read(fd, &t, 1);
		i++;
	}
	buf[i] = 0;
	return (buf);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open ("test.txt",	O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close (fd);
	return (0);
}
