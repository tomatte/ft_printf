/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:59:59 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/08 22:26:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	init_sign(t_sign **sign)
{
	(*sign)->minus = 0;
	(*sign)->zero = 0;
	(*sign)->dot = 0;
	(*sign)->ht = 0;
	(*sign)->spc = 0;
	(*sign)->plus = 0;
	(*sign)->type = 0;
	(*sign)->fill = 0;
	(*sign)->is_valid = 1;
}

void	sign_place(const char *str, t_sign **sign, int c)
{
	if (ft_strchr(CONVERSION, c))
	{
		(*sign)->type = c;
		(*sign)->is_valid = 1;
	}
	else if (!ft_strchr(FORMAT, c))
		(*sign)->is_valid = 0;
	else if (c == '-')
		(*sign)->minus = 1;
	else if (c == '0')
		(*sign)->zero = 1;
	else if (c == '.')
		(*sign)->dot = 1;
	else if (c == '#')
		(*sign)->ht = 1;
	else if (c == ' ')
		(*sign)->spc = 1;
	else if (c == '+')
		(*sign)->plus = 1;
}
