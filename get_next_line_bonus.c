/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:56:24 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/27 16:02:33 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buf;
	int			l;

	if (fd == -1)
		return (NULL);
	l = read(fd, 0, 0);
	if (l < 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (ft_strchr(str[fd], '\n') == 0)
		l = read(fd, buf, BUFFER_SIZE);
	if (l == 0 && !str[fd])
	{
		free(buf);
		return (NULL);
	}
	if (l == 0 && str[fd][0] == 0)
	{
		free(buf);
		free(str[fd]);
		return (0);
	}
	str[fd] = ft_buffinfline(fd, l, str[fd], buf);
	return (ft_line(str[fd]));
}

char	*ft_buffinfline(int fd, int l, char *str, char *buf)
{
	buf[l] = 0;
	str = ft_strjoin(str, buf);
	while (ft_strchr(str, '\n') == 0 && l != 0)
	{
		buf[0] = 0;
		l = read(fd, buf, BUFFER_SIZE);
		buf[l] = 0;
		str = ft_strjoin(str, buf);
	}
	free (buf);
	return (str);
}

char	*ft_line(char	*str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc ((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
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
		while (str[i + j])
		{
			ref[j] = str[i + j];
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
	//int	i = 0;

	fd = open ("big_line_no_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}*/
