/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/13 19:54:23 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(va_list ap, int *c_n)
{
	char	*s;
	int		c;

	c = va_arg(ap, int);
	if (!c)
	{
		(*c_n)++;
		return (ft_strdup(""));
	}
	s = (char *) malloc(2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

static char	*print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

void	ft_convert(t_list **sm, t_sign **sign, va_list ap, int *c_n)
{
	char	*str;

	str = NULL;
	if (!(*sign)->is_valid || ((*sign)->is_valid && !(*sign)->type))
		return (init_sign(sign));
	if ((*sign)->type == 'd' || (*sign)->type == 'i')
		str = print_int(sign, ap);
	if ((*sign)->type == 's')
		str = print_str(ap);
	else if ((*sign)->type == 'c')
		str = print_char(ap, c_n);
	else if ((*sign)->type == 'x' || (*sign)->type == 'X')
		str = print_hex(sign, ap, (*sign)->type);
	else if ((*sign)->type == 'p')
		str = print_pointer(sign, ap);
	else if ((*sign)->type == 'u')
		str = print_uint(sign, ap);
	else if ((*sign)->type == '%')
		str = ft_strdup("%");
	fill(&str, sign);
	init_sign(sign);
	if (!str)
		return ;
	ft_lstadd_back(sm, ft_lstnew((void *) str));
}