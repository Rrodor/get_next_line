/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:00:30 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/13 20:15:27 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linesize(int	fd)
{
	size_t	i;
	int	l;
	char	c;

	i = 0;
	l = read(fd, &c, 1);
	while (c != '\n' && l)
	{
		l = read(fd, &c, 1);
		i++;
	}
	return (i);
}

/*
int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%ld", ft_linesize(fd));
	close (fd);
	return (0);
}*/
