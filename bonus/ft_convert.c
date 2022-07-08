/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/08 20:17:42 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_int(t_sign **sign, va_list ap)
{
	char	*str;
	char	*aux;
	int		num;

	num = va_arg(ap, int);
	str = ft_itoa(num);
	if (!str)
		return (NULL);
	if (num >= 0 && ((*sign)->plus || (*sign)->spc))
	{
		if ((*sign)->plus)
			aux = ft_strjoin("+", str);
		else if ((*sign)->spc)
			aux = ft_strjoin(" ", str);
		if (!aux)
			return (NULL);
		free(str);
		str = aux;
	}
	return (str);
}

void	ft_convert(t_list **sm, t_sign **sign, va_list ap)
{
	char	*str;

	str = NULL;
	if (!(*sign)->is_valid || ((*sign)->is_valid && !(*sign)->type))
		return ;
	if ((*sign)->type == 'd' || (*sign)->type == 'i')
		str = print_int(sign, ap);
	init_sign(sign);
	if (!str)
		return ;
	ft_lstadd_back(sm, ft_lstnew((void *) str));
}