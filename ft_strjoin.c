/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:20:19 by momahdam          #+#    #+#             */
/*   Updated: 2025/10/22 22:27:52 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res_str = (char *)malloc(i + j + 1);
	if (!res_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		res_str[i] = s1[i];
	j = 0;
	while (s2[j])
		res_str[i++] = s2[j++];
	res_str[i] = '\0';
	return (res_str);
}
