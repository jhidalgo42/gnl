/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhidalgo <jhidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:01:35 by jhidalgo          #+#    #+#             */
/*   Updated: 2021/04/30 17:46:39 by jhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_find(char * str, char c)
{
	int	i;

	i = 0;
	if (str[i] == c)
		return (-1);
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

int	ft_next_line(char **line, char **memory, ssize_t buff)
{
	size_t	len;
	int		rtn;
	
	len = (ft_find(*memory, '\n'));
	if (buff < 0)
		rtn = -1;
	else if (buff == 0 && ft_find(*memory, '\n') == (int)ft_strlen(*memory))
		rtn = 0;
	else
		rtn = 1;
	if (*memory[0] == '\n')
		*line = ft_substr(*memory, 0, 1);
	else
		*line = ft_substr(*memory, 0, len);
	if (!line)
		return (-1);
	*memory = ft_strchr(*memory, '\n');
	return (rtn);
}

int	get_next_line(int fd, char **line)
{
	static char *memory[4096];
	char	tmp[BUFFER_SIZE + 1];
	char	*aux;
	ssize_t	buff;
	
	buff = 1;
	if ((fd < 0 || fd > 4096) || (!line || BUFFER_SIZE < 1))
		return (-1);
	if (!memory[fd])
		memory[fd] = ft_strdup("");
	while((ft_find(memory[fd], '\n') == (int)ft_strlen(memory[fd])) && buff > 0)
	{	
		buff = read(fd, tmp, BUFFER_SIZE);
		tmp[buff] = '\0';
		if (buff == -1)
		{
			return (-1);
		}
		aux = ft_strjoin(memory[fd], tmp);
		free (memory[fd]);
		memory[fd] = aux;
		ft_bzero(tmp, BUFFER_SIZE);
	}
	return (ft_next_line (line, &memory[fd], buff));
}


int main(void)
{
    char *line;
    int fd;
	int	r;

	//r = 1;
	fd = open("hola.txt", O_RDONLY);
	// size = get_next_line(fd, &line);
	//printf("%s\n", line);
	// if (*line)
	// 	free(line);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		//printf("100000%s\n", line);
		printf("NEXT LINE: %s\n", line);
		free(line);	
	}

	// printf("%s\n", line);
	// free (line);
	// line = NULL;
	close(fd);
	//system("leaks a.out");
    //while(1);
	return (0);
}