/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhidalgo <jhidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:01:37 by jhidalgo          #+#    #+#             */
/*   Updated: 2021/05/03 21:27:49 by jhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define	GET_NEXT LINE

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_find(char * str, char c);
#endif