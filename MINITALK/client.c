/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:06:21 by airis             #+#    #+#             */
/*   Updated: 2022/02/02 17:46:29 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		usleep(100);
	}
}

static void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

static int	ft_atoi(const char *str)
{
	char				neg;
	unsigned long long	num;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	neg = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > LONG_MAX - 1 && neg == 1)
		return (0);
	if (num > LONG_MAX && neg == 0)
		return (-1);
	if (neg)
		return (-num);
	else
		return (num);
}

int	main(int argc, char*argv[])
{
	pid_t	pid;
	char	*str;

	if (argc < 3)
	{
		ft_putstr("\e[1;31m");
		ft_putstr("Error: Проверьте аргументы!! \nПример ./client PID \"BlaBla\"");
		ft_putstr("\e[0m");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_str(pid, str);
	return (0);
}
