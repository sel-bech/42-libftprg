/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bech <sel-bech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:01:36 by sel-bech          #+#    #+#             */
/*   Updated: 2024/10/31 14:17:41 by sel-bech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (find[0] == '\0')
		return ((char *)src);
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (src[i + j] == find[j] && (i + j) < len && find[j] != '\0')
		{
			j++;
		}
		if (find[j] == '\0')
			return ((char *)(src + i));
		i++;
	}
	return (0);
}
