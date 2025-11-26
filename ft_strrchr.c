/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:34:47 by momahdam          #+#    #+#             */
/*   Updated: 2025/10/29 16:11:26 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	cc;

	if (!s)
		return (NULL);
	cc = (char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == cc)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
