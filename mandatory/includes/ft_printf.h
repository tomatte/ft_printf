/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:54:54 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/07 19:59:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *str, ...);
void	ft_printchar(int c, int *count);
void	ft_printstr(char *str, int *count);

#endif