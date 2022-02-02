/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:17:30 by airis             #+#    #+#             */
/*   Updated: 2021/12/16 22:57:59 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_numb_size(unsigned int numb)
{
	int	len;

	len = 0;
	if (numb == 0)
		len++;
	while (numb != 0)
	{
		numb /= 10;
		len++;
	}
	return (len);
}

static void	ft_rev(char *str)
{
	int		len;
	char	c;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_numb_size(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	ft_rev(str);
	return (str);
}
