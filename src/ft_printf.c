/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:27:23 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/05 20:36:31 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	ft_printstr(char *str, int *count)
{
	if (str == NULL)
	{
		ft_putstr("(NULL)");
		*count += ft_strlen("(NULL)");
		free(str);
		return ;
	}
	*count += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	ft_printchar(int c, int *count)
{
	ft_putchar((char) c);
	*count += 1;
}

void	ft_pointerstr(va_list ap, int *ct)
{
	char				*str;
	long unsigned int	address;

	address = va_arg(ap, long unsigned);
	if (!address)
	{
		ft_printstr(ft_strdup("(nil)"), ct);
		return ;
	}
	str = ft_itohex(address);
	ft_printstr(ft_strjoin("0x", str), ct);
	free(str);
}

static void	format_specifier(const char **str, va_list ap, int *ct)
{
	(*str)++;
	if (**str == '%')
		ft_printchar(**str, ct);
	else if (**str == 'c')
		ft_printchar(va_arg(ap, int), ct);
	else if (**str == 's')
		ft_printstr(ft_strdup(va_arg(ap, char *)), ct);
	else if (**str == 'd' || **str == 'i')
		ft_printstr(ft_itoa(va_arg(ap, int)), ct);
	else if (**str == 'u')
		ft_printstr(ft_uitoa(va_arg(ap, unsigned int)), ct);
	else if (**str == 'x')
		ft_printstr(ft_itohex(va_arg(ap, unsigned int)), ct);
	else if (**str == 'X')
		ft_printstr(ft_strtoupper(ft_itohex(va_arg(ap, unsigned int))), ct);
	else if (**str == 'p')
		ft_pointerstr(ap, ct);
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg_ptr;

	count = 0;
	va_start(arg_ptr, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			format_specifier(&str, arg_ptr, &count);
		else
		{
			count++;
			ft_putchar(*str);
			str++;
		}
	}
	return (count);
}
