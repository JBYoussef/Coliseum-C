/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:49:54 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/22 16:50:21 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_sep_words(char **strs, int size, char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		pos;
	int		size;

	if (s == NULL)
		return (NULL);
	pos = -1;
	size = 0;
	while (s[++pos] != '\0')
	{
		if (s[pos] != c && (s[pos + 1] == c || s[pos + 1] == '\0'))
			size++;
	}
	strs = ft_calloc(size + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	strs = ft_sep_words(strs, size, (char *)s, c);
	return (strs);
}

static char	**ft_sep_words(char **strs, int size, char *s, char c)
{
	int	count;
	int	c_word;
	int	temp;

	count = 0;
	c_word = 0;
	while (c_word < size)
	{
		while (s[count] == c)
			count++;
		temp = count;
		while (s[temp] != c && s[temp] != '\0')
			temp++;
		strs[c_word] = ft_calloc((temp - count + 1), sizeof(char));
		ft_memcpy((void *)strs[c_word], (const void *)&s[count], temp - count);
		strs[c_word][temp - count] = '\0';
		count = temp;
		c_word++;
	}
	strs[c_word] = NULL;
	return (strs);
}
