/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:24:58 by airis             #+#    #+#             */
/*   Updated: 2021/12/04 02:04:51 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchrendl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[k])
		str[i++] = (char)s1[k++];
	k = 0;
	while (s2[k])
		str[i++] = (char)s2[k++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_out_line(char *stat_line)
{
	char	*out_line;
	size_t	i;

	i = 0;
	while (stat_line[i] && stat_line[i] != '\n')
		i++;
	out_line = malloc(i + 2);
	if (!out_line)
		return (NULL);
	i = 0;
	while (stat_line[i] && stat_line[i] != '\n')
	{
		out_line[i] = stat_line[i];
		i++;
	}
	if (stat_line[i] == '\n')
		out_line[i++] = '\n';
	else
		out_line[i++] = '\0';
	out_line[i] = '\0';
	return (out_line);
}

char	*ft_update_stat_line(char *stat_line)
{
	int		i;
	int		j;
	char	*new_stat_line;

	if (!stat_line)
		return (NULL);
	i = 0;
	while (stat_line[i] && stat_line[i] != '\n')
		i++;
	if (!stat_line[i])
	{
		free(stat_line);
		return (NULL);
	}
	new_stat_line = (char *)malloc(ft_strlen(stat_line) - i + 2);
	if (!new_stat_line)
		return (NULL);
	i++;
	j = 0;
	while (stat_line[i])
		new_stat_line[j++] = stat_line[i++];
	new_stat_line[j] = '\0';
	free(stat_line);
	return (new_stat_line);
}
