#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# include <fcntl.h>

typedef struct	s_gnl
{
	char		*buf;
	int			count;
	int			i;
	int			nl;
	int			fd;
}				t_gnl;
int				get_next_line(int const fd, char **line);
#endif
