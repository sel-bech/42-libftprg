/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bech <sel-bech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:31:28 by sel-bech          #+#    #+#             */
/*   Updated: 2024/10/25 12:31:37 by sel-bech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*sc;

	i = 0;
	dst = dest;
	sc = src;
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dest);
}
