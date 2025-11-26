/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:20:46 by momahdam          #+#    #+#             */
/*   Updated: 2025/10/26 17:31:25 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(long n1)
{
	int	len;

	len = 1;
	if (n1 < 0)
	{
		n1 = -n1;
		len++;
	}
	while (n1 / 10 > 0)
	{
		len++;
		n1 /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	l;

	l = n;
	len = ft_intsize(l);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (l == 0)
		str[0] = '0';
	if (l < 0)
	{
		str[0] = '-';
		l = -l;
	}
	str[len] = '\0';
	while (l != 0 && len >= 0)
	{
		str[--len] = (l % 10) + 48;
		l /= 10;
	}
	return (str);
}
