/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:05:05 by momahdam          #+#    #+#             */
/*   Updated: 2025/10/29 16:44:18 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*data;

	if (!str)
		return (NULL);
	data = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		data[i] = c;
		i++;
	}
	return ((unsigned char *)str);
}
