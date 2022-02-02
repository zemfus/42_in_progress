/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:39:18 by airis             #+#    #+#             */
/*   Updated: 2021/12/16 22:57:53 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (*str)
	{
		write(1, str++, 1);
		size++;
	}
	return (size);
}

int	ft_print_int(int numb)
{
	char	*n;
	int		size;

	n = ft_itoa(numb);
	size = ft_print_str(n);
	free(n);
	return (size);
}

int	ft_print_uint(unsigned int numb)
{
	char	*n;
	int		size;

	n = ft_utoa(numb);
	size = ft_print_str(n);
	free(n);
	return (size);
}

int	ft_print_x_and_upx(unsigned int numb, int flag)
{
	char	*code;
	int		size;

	size = 0;
	code = "0123456789abcdef0123456789ABCDEF";
	if (numb < 16)
	{
		write(1, &code[numb + 16 * flag], 1);
		return (size + 1);
	}
	else
	{
		size = ft_print_x_and_upx(numb / 16, flag);
		write(1, &code[numb % 16 + 16 * flag], 1);
	}
	return (size + 1);
}

int	ft_print_pointer(unsigned long numb)
{
	char	*code;
	int		size;

	size = 0;
	code = "0123456789abcdef";
	if (numb < 16)
	{
		write(1, "0x", 2);
		write(1, &code[numb], 1);
		return (size + 3);
	}
	else
	{
		size = ft_print_pointer(numb / 16);
		write(1, &code[numb % 16], 1);
	}
	return (size + 1);
}
