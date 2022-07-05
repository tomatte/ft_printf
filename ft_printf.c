/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:27:23 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/05 03:07:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/ft_printf.h"

int	ft_printstr(va_list ap, int flag)
{
	char	*str;
	int		count;

	count = 0;
	if (flag == 2)
	{
		ft_putstr("0x");
		count += 2;
		str = ft_itohex(va_arg(ap, long unsigned int))
	}
	count += ft_strlen(str);
	return (count);
}

int	ft_printchar(char c)
{
	ft_putchar('%');
	return (1);
}

static void	format_specifier(const char **str, va_list ap)
{
	(*str)++;
	if (**str == '%')
		
	else if (**str == 'c')
		ft_putchar(va_arg(ap, int));
	else if (**str == 's')
		ft_putstr(va_arg(ap, char *));
	else if (**str == 'd' || **str == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (**str == 'u')
		ft_put_uint(va_arg(ap, unsigned int));
	else if(**str == 'x')
		ft_putstr(ft_itohex(va_arg(ap, long unsigned)));
	else if(**str == 'X')
		ft_putstr(ft_strtoupper(ft_itohex(va_arg(ap, long unsigned))));
 	else if(**str == 'p')
		print_pointer(ap);
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

	int	*p = &idade;

 	// ft_printf("Char: %c\n", 'c');
	// ft_printf("Olá, %s! Seja bem vindo!\n", nome);
	// ft_printf("Idade: %d\n", 12);
	// ft_printf("Idade: %i\n", idade);
	// ft_printf("MAX_INT: %u \nnegative: %u \nten: %u \n", INT_MAX, -1, 10);
	// ft_printf("Idade: %x\n", 48237793823);
	// ft_printf("Idade: %X\n", 48237793823);
	// ft_printf("Pointer: %p\n", p);
	// ft_printf("Percentage: %%\n");

	ft_printf("%p\n", p);
	printf("%p\n", p);
	return (0);
}