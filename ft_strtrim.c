/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bech <sel-bech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:23:33 by sel-bech          #+#    #+#             */
/*   Updated: 2024/11/01 09:38:29 by sel-bech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != 0 && ft_strchr(set, s1[i]))
		i += 1;
	while (j > i && ft_strchr(set, s1[j]))
		j -= 1;
	result = (char *)malloc(j - i + 2);
	if (result == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		result[k] = s1[i];
		i += 1;
		k += 1;
	}
	result[k] = 0;
	return (result);
}

/*int	main(void)
{
	const char	*s1 = "   Hello, World!   ";
	const char	*set = " ";
	char		*trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	if (trimmed_str)
	{
		printf("Original string: '%s'\n", s1);
		printf("Trimmed string: '%s'\n", trimmed_str);
		free(trimmed_str);
	}
	return (0);
}*/
