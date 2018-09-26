/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:06:47 by anhloba           #+#    #+#             */
/*   Updated: 2018/06/28 13:25:55 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	view_konec(char **s, char **line, int r, int fd)
{
	size_t	i;
	char	*t;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i])
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		t = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = t;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		if (r == BUFF_SIZE)
			get_next_line(fd, line);
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	char		buf[BUFF_SIZE + 1];
	char		*t;
	int			r;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		t = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = t;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	view_konec(s, line, r, fd);
	return (1);
}
