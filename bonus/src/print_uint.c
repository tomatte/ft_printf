/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:57:10 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/12 20:48:57 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(char **str, t_sign **sign)
{
	char	*n0;
	char	*aux;

	if (!(*sign)->dot)
		return ;
	n0 = set_n0(str, sign);
	if (!n0)
		return ;
	aux = ft_strjoin(n0, *str);
	if (!aux)
		return ;
	free(n0);
	if (*str)
		free(*str);
	*str = aux;
}

char	*print_uint(t_sign **sign, va_list ap)
{
	char			*str;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	str = ft_uitoa(num);
	if (!str)
		return (NULL);
	precision(&str, sign);
	return (str);
}
