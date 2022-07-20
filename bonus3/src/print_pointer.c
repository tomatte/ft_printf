/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:46:07 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/18 22:13:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(char **str, t_sign **sign, long unsigned int num)
{
	char	*n0;
	char	*aux;

	if ((*sign)->dot == -1)
		return ;
	if (!(*sign)->dot && !num)
	{
		free(*str);
		*str = ft_strdup("");
		return ;
	}
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

static char	*number_tohex(long unsigned int number, t_sign **sign)
{
	char	*ptr;

	ptr = ft_itohex(number);
	if (!ptr)
		return (NULL);
	if ((*sign)->zero && (*sign)->zero > (*sign)->dot)
	{
		if ((*sign)->zero > 2)
			(*sign)->zero -= 2;
		if (((*sign)->spc || (*sign)->plus) && (*sign)->zero)
			(*sign)->zero--;
		(*sign)->dot = (*sign)->zero;
		(*sign)->zero = 0;
	}
	precision(&ptr, sign, number);
	return (ptr);
}

static void	plus_or_spc(t_sign **sign, char **ptr)
{
	char	*aux;
	if ((*sign)->plus || (*sign)->spc)
	{
		aux = *ptr;
		if ((*sign)->plus)
			*ptr = ft_strjoin("+", *ptr);
		else if ((*sign)->spc)
			*ptr = ft_strjoin(" ", *ptr);
		free(aux);
	}
}

char	*print_pointer(t_sign **sign, va_list ap)
{
	char				*ptr;
	char				*aux;
	long unsigned int	address;

	address = va_arg(ap, long unsigned);
	if (!address)
	{
		if ((*sign)->zero > (*sign)->fill)
			(*sign)->fill = (*sign)->zero;
		return (ft_strdup("(nil)"));
	}
	ptr = number_tohex(address, sign);
	aux = ptr;
	ptr = ft_strjoin("0x", ptr);
	if (!ptr)
		return (NULL);
	free(aux);
	plus_or_spc(sign, &ptr);
	return (ptr);
}
