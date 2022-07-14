/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/14 19:35:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char(va_list ap, int *len)
{
	ft_putchar(va_arg(ap, int));
	(*len)++;
}

/* static char	*print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
} */

void	ft_convert(t_sign **sign, va_list ap, int *len)
{
	char	*str;

	str = NULL;
	if (!(*sign)->is_valid || ((*sign)->is_valid && !(*sign)->type))
		return (init_sign(sign));
	if ((*sign)->type == 'c')
		print_char(ap, len);
	// else if ((*sign)->type == 's')
	// 	str = print_str(ap);
	// if ((*sign)->type == 'd' || (*sign)->type == 'i')
	// 	str = print_int(sign, ap);
	// else if ((*sign)->type == 'x' || (*sign)->type == 'X')
	// 	str = print_hex(sign, ap, (*sign)->type);
	// else if ((*sign)->type == 'p')
	// 	str = print_pointer(sign, ap);
	// else if ((*sign)->type == 'u')
	// 	str = print_uint(sign, ap);
	// else if ((*sign)->type == '%')
	// 	str = ft_strdup("%");
	// fill(&str, sign);
	init_sign(sign);
	if (!str)
		return ;
}