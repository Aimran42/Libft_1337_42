/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:20:09 by momahdam          #+#    #+#             */
/*   Updated: 2025/10/24 22:39:14 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(const char *str, char c);
static void	*free_w(char **str, int count);
static char	*ft_word(char const *s, int start, int end);
static int	split_words(const char *s, char c, char **res, int is_word);

char	**ft_split(const char *s, char c)
{
	char		**res;
	int			is_word;
	int			check;

	if (!s)
		return (NULL);
	res = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	is_word = -1;
	check = split_words(s, c, res, is_word);
	if (check == 1)
		return (NULL);
	return (res);
}

static int	word_counter(const char *str, char c)
{
	int		i;
	int		x;
	int		count;

	i = 0;
	x = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (str[i] == c)
			x = 0;
		i++;
	}
	return (count);
}

static char	*ft_word(char const *s, int start, int end)
{
	char		*word;
	int			i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_w(char **str, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	split_words(const char *s, char c, char **res, int is_word)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && is_word < 0)
			is_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && is_word >= 0)
		{
			res[j] = ft_word(s, is_word, i);
			if (!(res[j]))
			{
				free_w (res, j);
				return (1);
			}
			is_word = -1;
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (0);
}
