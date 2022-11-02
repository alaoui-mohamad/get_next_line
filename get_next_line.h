#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_ret_line(char *ret);
char	*ft_ret(char *ret);
char	*ft_get_line(int fd, char *ret);
char	*get_next_line(int fd);

#endif