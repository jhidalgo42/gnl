/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhidalgo <jhidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:01:25 by jhidalgo          #+#    #+#             */
/*   Updated: 2021/04/30 17:42:48 by jhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)  //longitud de cadena de caracteres
{
	size_t	i;
	char	*sr;

	if (!str)
		return (0);
	sr = (char *)str;
	i = 0;
	while (*sr++ && i < 4294967295)
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
	{
		*ptr++ = 0;
	}
}

char	*ft_strdup(char *s) //Crea una cadena de memoria dinámica igual a otra que se da de entrada.
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen((char *)s) + 1) * (int) sizeof(char));
	if (!str)
	{	
		return (NULL);
	}
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2) //Une dos cadenas de caracteres.
{
	char	*str;
	char	*str1;

	if (!s1 && !s2)
		return (NULL);
	str = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	str1 = str;
	while (*s1)
	{
		*str++ = (char)*s1++;
	}
	while (*s2)
	{
		*str++ = (char)*s2++;
	}
	*str = '\0';

	return (str1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (((size_t)start + len) > ft_strlen((char *)s))
	{
		if ((size_t)start < ft_strlen((char *)s))
			len = ft_strlen((char *)s) - start;
		else
			return (NULL);
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	*str2;

	str = (char *)s;
	while (*str != c % 256)
	{
		if (*str == '\0')
			break ;
		str++;
	}
	if(*str == '\n')
		str++;
	str2 = ft_strdup(str);
	if (*s)
		free (s);
	return (str2);
}
