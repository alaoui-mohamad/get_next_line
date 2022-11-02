
#include "get_next_line.h"


char	*ft_ret_line(char *ret)
{
	int		i;
	char	*rret;

	i = 0;
	while (ret[i] && ret[i] != '\n')
		i++;
	rret = (char *)malloc(((i + 2) * sizeof(char)));
	if (!rret)
	{
		free(ret);
		return (NULL);
	}
	ft_strlcpy(rret, ret, i);
	if (ret[i] == '\n')
	{
		rret[i] = ret[i];
		i++;
	}
	rret[i] = '\0';
	return (rret);
}

char	*ft_ret(char *ret)
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
		return (NULL);
	i++;
	count = 0;
	while (ret[i])
		save[count++] = ret[i++];
	save[count] = '\0';
	free(ret);
	return (save);
}

char	*ft_get_line(int fd, char *ret)
{
	int		reads;
	char	*buffer;

	if (!ret)
		ret = calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reads = 1;
	while (!ft_strchr(ret, '\n') && reads != 0)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		buffer[reads] = '\0';
		ret = ft_strjoin(ret, buffer);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret = ft_get_line(fd, ret);
	line = ft_ret_line(ret);
	ret = ft_ret(ret);
	return (line);
}
