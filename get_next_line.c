/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:21:18 by belkarto          #+#    #+#             */
/*   Updated: 2022/11/10 17:39:58 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_nl(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	p = ft_substr(str, 0, i);
	if (p && *p == '\0')
		return (NULL);
	return (p);
}

char	*ft_rest(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	ptr = ft_substr(str, i, ft_strlen(str) - i);
	free (str);
	if (ptr && ptr[0] == 0)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		str[BUFFER_SIZE + 1];
	static char	*line = NULL;
	int			readed;
	char		*tmp;

	readed = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483648)
		return (NULL);
	while (1)
	{
		if (find_nl(line) == 1)
			break ;
		readed = read(fd, str, BUFFER_SIZE);
		if (readed == -1 || readed == 0)
		{
			tmp = ft_strdup(line);
			line = NULL;
			return (tmp);
		}
		str[readed] = '\0';
		line = ft_strjoin(line, str);
	}
	tmp = ft_line(line);
	line = ft_rest(line);
	return (tmp);
}
