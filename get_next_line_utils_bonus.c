/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:12 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/27 15:39:31 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	str = malloc((ft_strlen(s1) + BUFFER_SIZE + 1) * sizeof(char));
	str[0] = 0;
	if (!str)
		return (0);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}

char	*ft_strdup(char	*str)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = malloc ((ft_strlen(str) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = 0;
	ft_strcat(ret, str);
	return (ret);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	ld;

	i = 0;
	ld = 0;
	if (!dst && !src)
		return (0);
	if (dst[0])
		ld = ft_strlen(dst);
	while (src[i])
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = 0;
	return (dst);
}

int	ft_strchr(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			x = 1;
		i++;
	}
	return (x);
}
