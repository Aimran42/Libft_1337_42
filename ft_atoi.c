/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:32:56 by momahdam          #+#    #+#             */
/*   Updated: 2025/10/29 14:02:52 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

static int	sign_changer(const char *str, int *i)
{
	int	s;

	s = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			s = -1;
		(*i)++;
	}
	return (s);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				s;
	int				i;
	unsigned long	max;

	i = 0;
	res = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	s = sign_changer(str, &i);
	if (s == 1)
		max = MAX_LONG_L;
	else
		max = MIN_LONG_L;
	while (ft_isdigit(str[i]))
	{
		if (res > max / 10
			|| (res == max / 10 && (unsigned long)str[i] - '0' > max % 10))
			return (ft_long(s));
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)res * s);
}
