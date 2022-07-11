/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:59:59 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/11 16:41:30 by dbrandao         ###   ########.fr       */
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

void	is_digit_alone(const char *str, t_sign **sign, int *index)
{
	int	i;
	int	n;

	if (!ft_isdigit(*str))
		return ;
	n = 0;
	i = -1;
	while (ft_isdigit(str[++i]))
		n = (n * 10) + str[i] - 48;
	if (str[i] != '.' && !ft_strchr(CONVERSION, str[i]))
		(*sign)->is_valid = 0;
	else
		(*sign)->fill = n;
	(*index) += i;
}

void	dot_case(const char *str, t_sign **sign, int c, int *index)
{
	int	i;
	int	n;

	if (c != '.')
		return ;
	str++;
	if ((!ft_isdigit(*str) && !ft_strchr("diuxX", *str)) || !*str)
		(*sign)->is_valid = 0;
	if (ft_strchr("diuxX", *str))
		(*sign)->type = *str;
	n = 0;
	i = -1;
	while (ft_isdigit(str[++i]))
		n = (n * 10) + str[i] - 48;
	if (!ft_strchr("diuxX", str[i]) || !*str)
	{
		(*sign)->is_valid = 0;
		return ;
	}
	*index += i + 1;
	(*sign)->type = str[i];
	(*sign)->dot = n;
}

void	sign_place(t_sign **sign, int c)
{
	if (((*sign)->dot || (*sign)->zero) && (*sign)->is_valid)
		return ;
	if (ft_strchr(CONVERSION, c))
	{
		(*sign)->type = c;
		(*sign)->is_valid = 1;
	}
	else if (!ft_strchr(FORMAT, c))
		(*sign)->is_valid = 0;
	else if (c == '-')
		(*sign)->minus = 1;
	else if (c == '#')
		(*sign)->ht = 1;
	else if (c == ' ')
		(*sign)->spc = 1;
	else if (c == '+')
		(*sign)->plus = 1;
}

char	*set_n0(char **str, t_sign **sign)
{
	char	*aux;
	int		i;
	char	*n0;

	i = (*sign)->dot - ft_strlen(*str);
	if (**str == '-')
		i--;
	n0 = (char *) malloc(i + 1);
	if (!n0)
		return (NULL);
	if (**str == '-')
		aux = ft_strdup((*str) + 1);
	else
		aux = ft_strdup((*str));
	if (!aux)
		return (NULL);
	free(*str);
	*str = aux;
	ft_memset((void *) n0, '0', i);
	n0[i] = '\0';
	return (n0);
}