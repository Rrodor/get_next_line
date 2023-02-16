/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:38:42 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/16 16:42:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *str, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && i < 1000)
		i++;
	while (buf[j] && i + j < 1000)
	{
		str[i + j] = buf[j];
		j++;
	}
	return (str);
}

#include <stdio.h>
int	main()
{
	char	str[100] = "salut";

	printf("%s", ft_strcat(str, " a tous"));
	return (0);
}
