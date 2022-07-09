/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 05:15:03 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/09 18:36:29 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(char **str, t_sign **sign)
{
	int		i;
	char	*n0;
	char	*aux;

	i = (*sign)->dot - ft_strlen(*str);
	printf("29: %d\n", i);
	if (i <= 0)
		return ;
	n0 = (char *) malloc(i + 1);
	if (!n0)
		return ;
	ft_memset((void *) n0, '0', i);
	n0[i] = '\0';
	aux = ft_strjoin(n0, *str);
	if (!aux)
		return ;
	free(n0);
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
	precision(&str, sign);
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
		return (init_sign(sign));
	if ((*sign)->dot)
		precision(&str, sign);
	if ((*sign)->type == 'd' || (*sign)->type == 'i')
		str = print_int(sign, ap);
	init_sign(sign);
	if (!str)
		return ;
	ft_lstadd_back(sm, ft_lstnew((void *) str));
}