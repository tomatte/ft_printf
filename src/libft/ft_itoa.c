/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:04:06 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/05 07:36:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	negative_case(int *num, int *len)
{
	if (*num < 0)
	{
		(*len)++;
		*num *= -1;
		return (-1);
	}
	return (1);
}

char	*ft_itoa(int n)
{
	char	*s_num;
	int		len;
	int		sign;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = num_len(n);
	sign = negative_case(&n, &len);
	s_num = (char *) malloc(sizeof(char) * len + 1);
	if (!s_num)
		return (NULL);
	s_num[len] = '\0';
	while (--len >= 0)
	{
		if (sign == -1 && !len)
		{
			s_num[len] = '-';
			break ;
		}
		s_num[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s_num);
}
