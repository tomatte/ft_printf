/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:45:45 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/12 20:48:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(char **str, t_sign **sign, int num)
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
	if (num < 0)
	{
		n0 = aux;
		aux = ft_strjoin("-", aux);
		free(n0);
	}
	if (*str)
		free(*str);
	*str = aux;
}

static void	plus_or_space(char **str, int num, t_sign **sign)
{
	char	*aux;

	aux = NULL;
	if (num >= 0 && ((*sign)->plus || (*sign)->spc))
	{
		if ((*sign)->plus)
			aux = ft_strjoin("+", *str);
		else if ((*sign)->spc)
			aux = ft_strjoin(" ", *str);
		if (!aux)
			return ;
		free(*str);
		*str = aux;
	}
}

char	*print_int(t_sign **sign, va_list ap)
{
	char	*str;
	int		num;

	num = va_arg(ap, int);
	str = ft_itoa(num);
	if (!str)
		return (NULL);
	precision(&str, sign, num);
	plus_or_space(&str, num, sign);

	return (str);
}
