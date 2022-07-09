/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/09 18:52:45 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*set_n0(char **str, t_sign **sign, int num)
{
	char	*aux;
	int		i;
	char	*n0;

	i = (*sign)->dot - num_len(num);
	if (!ft_isdigit(**str))
		i++;
	n0 = (char *) malloc(i + 1);
	if (!n0)
		return (NULL);
	*n0 = **str;
	if (!ft_isdigit(**str))
		aux = ft_strdup((*str) + 1);
	else
		aux = ft_strdup((*str));
	if (!aux)
		return (NULL);
	free(*str);
	*str = aux;
	if (*n0 == '-' || *n0 == '+')
		ft_memset((void *) (n0 + 1), '0', i - 1);
	else
		ft_memset((void *) n0, '0', i);
	n0[i] = '\0';
	return (n0);
}

static void	precision(char **str, t_sign **sign, int num)
{
	int		i;
	char	*n0;
	char	*aux;


	n0 = set_n0(str, sign, num);
	aux = ft_strjoin(n0, *str);
	if (!aux)
		return ;
	free(n0);
	if (*str)
		free(*str);
	*str = aux;
}

static char	*print_int(t_sign **sign, va_list ap)
{
	char	*str;
	char	*aux;
	int		num;
	int		i;

	num = va_arg(ap, int);
	str = ft_itoa(num);
	if (!str)
		return (NULL);
	precision(&str, sign, num);
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
	if ((*sign)->type == 'c')
		str = print_char(va_arg(ap, int));
	init_sign(sign);
	if (!str)
		return ;
	ft_lstadd_back(sm, ft_lstnew((void *) str));
}