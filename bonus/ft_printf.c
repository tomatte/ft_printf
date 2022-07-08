/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:04:50 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/08 22:24:11 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	just_str(const char **str, t_list **sm)
{
	int		i;
	char	*jst;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if (!i)
		return ;
	jst = (char *) malloc(sizeof(char) * i + 1);
	if (!jst)
		return ;
	ft_strlcpy(jst, *str, i + 1);
	ft_lstadd_back(sm, ft_lstnew((void *) jst));
	*str = &(*str)[i];
}

void	number_specifier(const char *str)
{
	
}

void	verify_specifiers(const char **str, t_sign **sign, t_list **sm)
{
	int	c;
	int	i;

	if (!**str)
		return ;
	i = 0;
	while ((*str)[i])
	{
		c = (*str)[i + 1];
		sign_place(*str, sign, c);
		if (!(*sign)->is_valid || (*sign)->type || !c)
			break ;
		i++;
	}
	if (!(*sign)->is_valid || !c)
	{
		ft_lstadd_back(sm, ft_lstnew(ft_strdup("%")));
		(*str)++;
		init_sign(sign);
	}
	else
		(*str) = &(*str)[i + 2];
}

void	string_mount(const char **str, t_list **sm, va_list ap, t_sign **sign)
{
	while (**str)
	{
		just_str(str, sm);
		verify_specifiers(str, sign, sm);
		ft_convert(sm, sign, ap);
	}
}

int	print_str(t_list **sm)
{
	int	count;

	count = 0;
	while (*sm)
	{
		ft_putstr((char *) (*sm)->content);
		count += ft_strlen((char *) (*sm)->content);
		sm = &(*sm)->next;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_list	*s_mount;
	t_sign	*sign;
	int		len;

	s_mount = NULL;
	sign = (t_sign *) malloc(sizeof(t_sign));
	if (!sign)
		return (-1);
	init_sign(&sign);
	va_start(ap, str);
	string_mount(&str, &s_mount, ap, &sign);
	len = print_str(&s_mount);
	ft_lstclear(&s_mount, free);
	return (len);
}

int	main(void)
{
	ft_printf("a%da\n", 20);
	ft_printf("a% da\n", 20);
	ft_printf("a%+da\n", 20);
	ft_printf("a% da\n", -20);
	ft_printf("a% +da\n", 20);
	ft_printf("a%+ da\n", 20);
	ft_printf("a% +da\n", -20);
	ft_printf("a%+da\n", -20);
	return (0);
}
/* 
	haverá uma lista encadeada com todas as strings para printar

	just_str():
		se for string normal, ela será adicionada na lista encadeada
		o ponteiro irá avançar até um % ou nulo
	verify specifiers()
		irá analisar todas as flags após o % e atribuir ao s_sign
		
		caso for invalido, então irá adicionar o % à lista para ser printado
		avançará o ponteiro e reinicializará o s_sign
		
	
	//
 */