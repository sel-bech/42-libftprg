/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bech <sel-bech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:30:37 by sel-bech          #+#    #+#             */
/*   Updated: 2024/10/31 09:19:56 by sel-bech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char const *s, int start, int word_len)
{
	char	*word;
	int		j;

	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < word_len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;
	int	start;

	i = 0;
	word = 0;
	while (word < num_words)
	{
		word_len = 0;
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = ft_putword(s, start, word_len);
		if (!s2[word])
			return (free_array(s2, word), NULL);
		word++;
	}
	s2[word] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (NULL);
	return (ft_split_words(s, c, s2, num_words));
}
/*
int main()
{
    char *s = "  Hello, my name    is saad   ";
    char d = ' ';
    char **r;
    int i=0;

    r = ft_split(s, d);

    while(r[i] != NULL)
    {
        printf("Word %d: %s\t", i, r[i]);
	i++;
    }
    return (0);
}*/
