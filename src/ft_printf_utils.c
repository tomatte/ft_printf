/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:10:04 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/05 21:23:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printchar(int c, int *count)
{
	ft_putchar((char) c);
	*count += 1;
}

void	ft_printstr(char *str, int *count)
{
	*count += ft_strlen(str);
	ft_putstr(str);
	free(str);
}
