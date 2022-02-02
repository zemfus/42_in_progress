/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:30:12 by airis             #+#    #+#             */
/*   Updated: 2021/12/16 21:55:53 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sflags(char c)
{
	char	*str;

	str = FLAGS;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_print_param(char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (c == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(ap, int)));
	if (c == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_print_x_and_upx(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (ft_print_x_and_upx(va_arg(ap, unsigned int), 1));
	if (c == 'p')
		return (ft_print_pointer(va_arg(ap, unsigned long)));
	if (c == '%')
		return (ft_print_str("%"));
	return (0);
}

static int	ft_count_print_parse(const char *str, va_list ap)
{
	int	count_s;
	int	i;

	i = 0;
	count_s = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_sflags(str[i + 1]))
		{
			count_s += ft_print_param(str[i + 1], ap);
			i++;
		}
		else
		{
			write(1, str + i, 1);
			count_s++;
		}
		i++;
	}
	return (count_s);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count_s;

	va_start(ap, str);
	count_s = ft_count_print_parse(str, ap);
	va_end(ap);
	return (count_s);
}
