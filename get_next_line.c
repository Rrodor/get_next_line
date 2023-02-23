/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:56:24 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/24 00:01:44 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buf;
	int			l;

	if (fd == -1)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//l = read(fd, 0, 0);
	//if (l == 0)
	//{
	//	free(buf);
	//	return (NULL);
	//}
	l = 0;
	if (ft_strchr(str, '\n') == 0)
		l = read(fd, buf, BUFFER_SIZE);
	if (l == 0 && ft_strchr(str, '\n') == 0)
	{
		free(buf);
		free(str);
		return (0);
	}
	buf[l] = 0;
	str = ft_strjoin(str, buf);
	while (ft_strchr(str, '\n') == 0)
	{
		buf[0] = 0;
		l = read(fd, buf, BUFFER_SIZE);
		buf[l] = 0;
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (ft_line(str));
}

char	*ft_line(char	*str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
			i++;
	line = malloc ((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	str = ft_prepstr(str, i);
	line[i] = 0;
	return (line);
}

char	*ft_prepstr(char *str, int i)
{
	int		j;
	char	*ref;

	j = 0;
	ref = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!str[i])
		str[0] = 0;
	else
	{
		while (str[i + j + 1])
		{
			ref[j] = str[i + j + 1];
			j++;
		}
		ref[j] = 0;
		j = 0;
		while (ref[j])
		{
			str[j] = ref[j];
			j++;
		}
		str[j] = 0;
	}
	free(ref);
	return (str);
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;
	char	*str;

	fd = open ("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}*/
