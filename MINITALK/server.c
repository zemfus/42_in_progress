/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:06:19 by airis             #+#    #+#             */
/*   Updated: 2022/02/02 17:46:27 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>

static void	sig_handler(int sig)
{
	static char	buf;
	static int	bit = 7;

	if (sig == SIGUSR1)
		buf |= (1 << bit);
	if (sig == SIGUSR2)
		buf &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		write(1, &buf, 1);
	}
}

static void	ft_putnbr_fd(int n, int fd)
{
	char	*numb;

	numb = "0123456789\0";
	if (n < 0)
	{
		write(fd, "-", 1);
	}
	if (n == INT_MIN)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (n < 0)
	{
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	write(fd, &numb[n % 10], 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
