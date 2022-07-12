/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/12 05:57:06 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(int c)
{
	char	*s;

	s = (char *) malloc(2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

void	ft_convert(t_list **sm, t_sign **sign, va_list ap)
{
	char	*str;

	str = NULL;
	if (!(*sign)->is_valid || ((*sign)->is_valid && !(*sign)->type))
		return (init_sign(sign));
	if ((*sign)->type == 'd' || (*sign)->type == 'i')
		str = print_int(sign, ap);
	else if ((*sign)->type == 'c')
		str = print_char(va_arg(ap, int));
	else if ((*sign)->type == 'x' || (*sign)->type == 'X')
		str = print_hex(sign, ap, (*sign)->type);
	else if ((*sign)->type == 'p')
		str = print_pointer(sign, ap);
	else if ((*sign)->type == 'u')
		str = print_uint(sign, ap);
	fill(&str, sign);
	init_sign(sign);
	if (!str)
		return ;
	ft_lstadd_back(sm, ft_lstnew((void *) str));
}