/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:04:50 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/11 18:25:18 by dbrandao         ###   ########.fr       */
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
		is_digit_alone(&(*str)[i + 1], sign, &i);
		dot_case(&(*str)[i + 1], sign, c, &i);
		sign_place(sign, c);
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
	va_end(ap);
	return (len);
}

int	main(void)
{
	int	a = 5;

	ft_printf("-------- TEST 1 ---------\n");
	ft_printf("|%d|\n", 9);
	ft_printf("|%.3d|\n", 9);
	ft_printf("|% d|\n", 9);
	
	ft_printf("\n-------- TEST 2 ---------\n");
	ft_printf("|%.3x|\n", 15);
	printf("|%.3x|\n", 15);

	ft_printf("\n-------- TEST 3 ---------\n");
	ft_printf("|% p|\n", &a);
	printf("|% p|\n", &a);
	return (0);
}
/* 
	------------
	fazer o (number) width e o (minus) por ultimo
	depois q todas as conversões ja foram feitas
	pois eles independem do numero convertido





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