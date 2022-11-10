/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:24:49 by belkarto          #+#    #+#             */
/*   Updated: 2022/11/10 18:04:30 by belkarto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *) malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		str = (char *)malloc(1);
	else if (len > s_len - start)
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && i + start < s_len && s[i])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1 && s1[++i] != '\0')
		str[i] = s1[i];
	free(s1);
	i = -1;
	while (s2 && s2[++i] != '\0')
		str[i + len_s1] = s2[i];
	str[len_s1 + len_s2] = 0;
	return (str);
}
