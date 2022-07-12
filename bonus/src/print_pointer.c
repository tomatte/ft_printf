/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:46:07 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/11 18:31:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_pointer(t_sign **sign, va_list ap)
{
	char				*ptr;
	char				*aux;
	long unsigned int	address;

	address = va_arg(ap, long unsigned);
	if (!address)
		return (ft_strdup("(nil)"));
	ptr = ft_itohex(address);
	aux = ptr;
	ptr = ft_strjoin("0x", ptr);
	if (!ptr)
		return (NULL);
	free(aux);
	if ((*sign)->plus || (*sign)->spc)
	{
		aux = ptr;
		if ((*sign)->plus)
			ptr = ft_strjoin("+", ptr);
		else if ((*sign)->spc)
			ptr = ft_strjoin(" ", ptr);
		if (!ptr)
			return (NULL);
		free(aux);
	}
	return (ptr);
}
