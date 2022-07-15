/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/15 04:46:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char(va_list ap, int *len, t_sign **sign)
{
	int		c;
	char	*str;

	str = NULL;
	fill_c(&str, sign);
	c = va_arg(ap, int);
	if (str && !(*sign)->minus)
		ft_putstr(str);
	ft_putchar(c);
	if (str && (*sign)->minus)
	{
		ft_putstr(str);
		(*sign)->minus = 0;
	}
	if (str)
	{
		(*len) += ft_strlen(str);
		free(str);
	}
	(*len)++;
}

char	*print_str(t_sign **sign, va_list ap)
{
	char	*str;
	char	*aux;
	int		len;

	str = va_arg(ap, char *);
	if (!str && ((*sign)->dot == -1 || (*sign)->dot >= 6))
		return (ft_strdup("(null)"));
	if (!str && ((*sign)->dot >= 0 && (*sign)->dot <= 5))
		return (ft_strdup(""));
	if ((*sign)->dot == -1)
		return (ft_strdup(str));
	len = ft_strlen(str);
	if ((*sign)->dot < len)
		len = (*sign)->dot;
	if (len <= 0)
		return (ft_strdup(""));
	aux = (char *) malloc(len + 1);
	if (!aux)
		return (ft_strdup(""));
	ft_memmove(aux, str, len);
	aux[len] = '\0';
	return (aux);
}

void	ft_convert(t_sign **sign, va_list ap, int *len)
{
	char	*str;

	str = NULL;
	if (!(*sign)->is_valid || ((*sign)->is_valid && !(*sign)->type))
		return (init_sign(sign));
	if ((*sign)->type == 'c')
		print_char(ap, len, sign);
	else if ((*sign)->type == 's')
		str = print_str(sign, ap);
	else if ((*sign)->type == 'p')
		str = print_pointer(sign, ap);
	if ((*sign)->type == 'd' || (*sign)->type == 'i')
		str = print_int(sign, ap);
	else if ((*sign)->type == 'u')
		str = print_uint(sign, ap);
	else if ((*sign)->type == 'x' || (*sign)->type == 'X')
		str = print_hex(sign, ap, (*sign)->type);
	else if ((*sign)->type == '%')
		str = ft_strdup("%");
	fill(&str, sign);
	init_sign(sign);
	if (str)
	{
		ft_putstr(str);
		*len += ft_strlen(str);
		free(str);
	}
}