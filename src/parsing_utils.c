/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmond <mosmond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:22:45 by mosmond           #+#    #+#             */
/*   Updated: 2025/12/22 16:00:37 by mosmond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	ft_countwords(char const *s)
{
	int	word_count;
	int	word;
	int	i;

	word_count = 0;
	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] == ' ' || s[i] == '\t') && s[i] && word == 1)
			word = 0;
		if ((s[i] != ' ' || s[i] != '\t') && s[i] && word == 0)
		{
			word = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

void	*ft_free(char **r)
{
	int	i;

	i = 0;
	if (!r)
		return (NULL);
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
	return (NULL);
}

int	ft_wordlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] && (str[len] != ' ' && str[len] != '\t'))
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
