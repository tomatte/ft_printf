/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:46:15 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/12 20:44:17 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	is_minus(t_sign **sign)
{
	if ((*sign)->minus)
	{
		if ((*sign)->zero > (*sign)->fill)
		{
			(*sign)->fill = (*sign)->zero;
			(*sign)->zero = 0;
		}
	}
}

static void	fill_spaces(char **str, t_sign **sign)
{
	char	*fill;
	char	*aux;
	int		len;

	len = ft_strlen(*str);
	if ((*sign)->fill > len)
	{
		fill = (char *) malloc((*sign)->fill - len + 1);
		if (!fill)
			return ;
		ft_memset(fill, ' ', (*sign)->fill - len);
		fill[(*sign)->fill - len] = '\0';
		aux = *str;
		if ((*sign)->minus)
			*str = ft_strjoin(*str, fill);
		else
			*str = ft_strjoin(fill, *str);
		free(aux);
		free(fill);
	}
}

static void	fill_zeros(char **str, t_sign **sign)
{
	int		len;
	char	*fill;
	char	*aux;

	len = ft_strlen(*str);
	if ((*sign)->zero > len)
	{
		fill = (char *) malloc((*sign)->zero - len + 1);
		if (!fill)
			return ;
		if (**str == '-')
		{
			*fill = '-';
			ft_memset(fill + 1, '0', (*sign)->zero - len - 1);
		}
		else
			ft_memset(fill, '0', (*sign)->zero - len);
		aux = *str;
		*str = ft_strjoin(fill, *str);
		free(aux);
		free(fill);
	}
}

void	fill(char **str, t_sign **sign)
{
	if ((!(*sign)->fill && !(*sign)->zero) || !*str)
		return ;
	is_minus(sign);
	fill_zeros(str, sign);
	fill_spaces(str, sign);
}