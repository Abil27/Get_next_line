/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoussei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 12:39:18 by ahoussei          #+#    #+#             */
/*   Updated: 2018/07/02 12:39:21 by ahoussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     add_null_char(int fd, char **buff, char **line)
{
    char *new_line;
    char *heap;

    new_line = ft_strchr(buff[fd], '\n');
    if (null_char)
    {
        heap = buff[fd];
        *new_line ='\0';
        *line = ft_strdup(buff[fd]);
        buff[fd] = ft_strdup(new_line + 1);
        free(heap);
        return (1);
    }
    else if (*buff[fd])
    {
        *line = ft_strdup(buff[fd]);
        buff[fd] = ft_strnew(BUFF_SIZE + 1);
        return (1);
    }
    return (0);
}

int     check_new_line(int fd, char **buff)
{
    char    *tmp;
    char    *leak;
    int     i;

    tmp = ft_strnew(BUFF_SIZE + 1);
    while ((i = read(fd, tmp, BUFF_SIZE)) > 0)
    {
        leak = buff[fd];
        buff[fd] = ft_strjoin(buff[fd], tmp);
        ft_strdel(&leak);
        ft_bzero(tmp, BUFF_SIZE);
    }
    free(tmp);
    return (i ? 1 : 0);
}

int     get_next_line(const int fd, char **line)
{
    static char     *buff[4864];

    if((BUFF_SIZE < 1 || fd < 0 || !line ||
        check_new_line(fd, &buff[fd])))
        return (-1);
    if (add_null_char(fd, &buff[fd], line))
        return (1);
    return (0);
}