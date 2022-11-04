/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hello <hello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:53:31 by m-alaoui          #+#    #+#             */
/*   Updated: 2022/11/04 17:05:21 by hello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_check_next(char *ret)
{
	int		i;
	int		count;
	char	*save;

	i = 0;
	while (ret[i] && ret[i] != '\n')
		i++;
	if (!ret[i])
	{
		free(ret);
		return (NULL);
	}
	save = (char *)malloc(sizeof(char) * (ft_strlen(ret) - i + 1));
	if (!save)
	{
		free(save);
		return (NULL);
	}
	i++;
	count = 0;
	while (ret[i])
		save[count++] = ret[i++];
	save[count] = '\0';
	free(ret);
	return (save);
}
char	*ft_ret_line(char *ret)
{
	int		i;
	char	*rret;

	i = 0;
	if (!ret[0])
		return (NULL);
	while (ret[i] && ret[i] != '\n')
		i++;
	rret = (char *)malloc(((i + 2) * sizeof(char)));
	if (!rret)
	{
		free(ret);
		return (NULL);
	}
	i = 0;
	while (ret[i] && ret[i] != '\n')
	{
		rret[i] = ret[i];
		i++;
	}
	if (ret[i] == '\n')
	{
		rret[i] = ret[i];
		i++;
	}
	rret[i] = '\0';
	return (rret);
}

char	*ft_get_line(int fd, char *ret)
{
	int		reads;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reads = 1;
	while (!ft_strchr(ret, '\n') && reads != 0)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads == -1)
		{
			if (ret != NULL)
				free(ret);
			free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		ret = ft_strjoin(ret, buffer);
	}
	free(buffer);
	return (ret);
}
char	*get_next_line(int fd)
{
	static char *ret[OPEN_MAX];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret[fd] = ft_get_line(fd, ret[fd]);
	if (!ret[fd])
		return (NULL);
	line = ft_ret_line(ret[fd]);
	ret[fd] = ft_check_next(ret[fd]);
	return (line);
}