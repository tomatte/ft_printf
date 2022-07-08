/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:54:54 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/08 22:25:51 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "libft.h"

//#include <stdio.h>

# define CONVERSION "cspdiuxX%"
# define FORMAT "-0.# +"

typedef struct	s_sign
{
	int	minus;
	int	zero;
	int	dot;
	int	ht;
	int	spc;
	int	plus;
	int	type;
	int	fill;
	int	is_valid;
}				t_sign;

char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *str, ...);
void	ft_printchar(int c, int *count);
void	ft_printstr(char *str, int *count);
void	init_sign(t_sign **sign);
void	sign_place(const char *str, t_sign **sign, int c);
void	ft_convert(t_list **sm, t_sign **sign, va_list ap);

#endif