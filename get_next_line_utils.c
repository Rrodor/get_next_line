/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:00:30 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/16 23:27:42 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleanbuf(char *buf, int fd)
{
	int			i;
	int			j;
	int			x;
	static char	str[BUFFER_SIZE * 10];
	char	*line;
	char	ref[BUFFER_SIZE];
	//char	test[BUFFER_SIZE];
	i = 0;
	j = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j = 1;
		i++;
	}
	if (j == 0)
		read(fd, buf, BUFFER_SIZE);
	i = 0;
	j = 0;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ft_strcat(str, buf);
	//printf("buf%sbuf\n\n", str);
	while (str[i] != '\n' && str[i] && i < BUFFER_SIZE * 10)
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		x = 1;
	line[i] = 0;
	i++;
	if (x == 1)
	{
		while (str[i] && i < BUFFER_SIZE)
		{
			ref[j] = str[i];
			j++;
			i++;
		}
	}
	ref[j] = 0;
	j = 0;
	while (ref[j])
	{
		str[j] = ref[j];
		j++;
	}
	str[j] = 0;
	//printf("A%sA\n", str);
	if (x == 0)
	{
		line = ft_strjoin(line, ft_cleanbuf(buf, fd));
		//printf("AAA%sAAA", line);
	}
	return (line);
}

char	*ft_strcat(char *str, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (buf[j])
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	str = malloc((ls1 + ls2 + 1)  * sizeof(char));
	if (!str)
		return (0);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
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

