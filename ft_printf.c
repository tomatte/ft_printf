/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:27:23 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/02 00:11:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/ft_printf.h"

static int	count_size()
{
	
}

static void	format_specifier(const char **str, va_list ap)
{
	(*str)++;
	if (**str == '%')
		ft_putchar('%');
	else if (**str == 'c')
		ft_putchar(va_arg(ap, int));
	else if (**str == 's')
		ft_putstr(va_arg(ap, char *));
	else if (**str == 'd' || **str == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (**str == 'u')
		ft_put_uint(va_arg(ap, unsigned int));
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	va_list arg_ptr;

	va_start(arg_ptr, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			format_specifier(&str, arg_ptr);
		ft_putchar(*str);
		str++;
	}
	return (0);
}

#include <stdio.h>
int	main(void)
{
	char	nome[] = "Daniel";
	int		idade = 12;

	ft_printf("Olá, %s! Seja bem vindo!\n", nome);
	ft_printf("Idade: %d\n", idade);
	ft_printf("MAX_INT: %u \nnegative: %u \nten: %u \n", INT_MAX, -1, 10);
	ft_printf("Percentage: %%\n");
	ft_printf("printf: %d\n", printf("123456789\n"));
	return (0);
}