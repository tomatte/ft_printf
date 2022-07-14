/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:04:50 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/14 19:37:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	just_str(const char **str)
{
	int		i;
	// char	*jst;

	i = -1;
	while ((*str)[++i] && (*str)[i] != '%')
		ft_putchar((*str)[i]);
	*str = &(*str)[i];
	return (i);
}

static void	verify_specifiers(const char **str, t_sign **sign, int *len)
{
	int	c;
	int	i;

	if (!**str)
		return ;
	i = 0;
	while ((*str)[i])
	{
		c = (*str)[i + 1];
		is_digit_alone(&(*str)[i + 1], sign, &i, &c);
		dot_case(&(*str)[i + 1], sign, c, &i);
		sign_place(sign, c);
		if (!(*sign)->is_valid || (*sign)->type || !c)
			break ;
		i++;
	}
	if (!(*sign)->is_valid || !c)
	{
		ft_putchar('%');
		(*str)++;
		init_sign(sign);
		(*len)++;
	}
	else
		(*str) = &(*str)[i + 2];
}

static int	string_mount(const char **str, va_list ap, t_sign **sign)
{
	int	len;

	len = 0;
	while (**str)
	{
		len += just_str(str);
		verify_specifiers(str, sign, &len);
		ft_convert(sign, ap, &len);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_sign	*sign;
	int		len;

	sign = (t_sign *) malloc(sizeof(t_sign));
	if (!sign)
		return (-1);
	init_sign(&sign);
	va_start(ap, str);
	len = string_mount(&str, ap, &sign);
	va_end(ap);
	free(sign);
	return (len);
}
