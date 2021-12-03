/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:23:40 by airis             #+#    #+#             */
/*   Updated: 2021/12/04 02:04:53 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_stat_line(char *stat_line, int fd)
{
	char	*add_stat_line;
	int		size;

	add_stat_line = malloc(BUFFER_SIZE + 1);
	if (!add_stat_line)
		return (NULL);
	size = 1;
	while (size && !ft_strchrendl(stat_line))
	{
		size = read(fd, add_stat_line, BUFFER_SIZE);
		if (size == -1)
		{
			free(add_stat_line);
			return (NULL);
		}
		add_stat_line[size] = '\0';
		stat_line = ft_strjoin(stat_line, add_stat_line);
	}
	free(add_stat_line);
	return (stat_line);
}

char	*get_next_line(int fd)
{
	static char	*stat_line;
	char		*out_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_line = ft_get_new_stat_line(stat_line, fd);
	if (!stat_line)
		return (NULL);
	out_line = ft_get_out_line(stat_line);
	if (!ft_strlen(out_line))
	{
		free(out_line);
		if (stat_line)
		{
			free(stat_line);
			stat_line = NULL;
		}
		return (NULL);
	}
	stat_line = ft_update_stat_line(stat_line);
	return (out_line);
}
