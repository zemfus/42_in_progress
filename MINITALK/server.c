/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:06:19 by airis             #+#    #+#             */
/*   Updated: 2022/02/16 19:11:26 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char	*ft_strjoin_mod(char const *s1, char ch)
{
	int		len;
	char	*str;
	int		i;

	if (!s1)
		return (0);
	i = 0;
	len = 0;
	while (s1[i++])
		len++;
	str = malloc(sizeof(*str) * (len + 1) + 1);
	if (str == 0)
		return (0);
	i = -1;
	while (++i < len)
		str[i] = s1[i];
	str[i++] = ch;
	str[i] = '\0';
	return (str);
}

// static char	*ft_strdup(const char *str)
// {
// 	int		len;
// 	int		j;
// 	char	*dest;

// 	j = 0;
// 	len = 0;
// 	while (str[len++])
// 		;
// 	dest = (char *)malloc(sizeof(*dest) * len + 1);
// 	if (dest == 0)
// 		return (0);
// 	while (j < len)
// 	{
// 		dest[j] = str[j];
// 		j++;
// 	}
// 	dest[j] = '\0';
// 	return (dest);
// }

static void	sig_handler(int sig)
{
	static char	buf;
	static int	bit = 7;
	static char	*str_to_print = "";
	static int	len = 0;

	if (sig == SIGUSR1)
		buf |= (1 << bit);
	bit--;
	if (bit == -1)
	{
		// if (!str_to_print)
		// 	str_to_print = ft_strdup("");
		if (buf != '\0')
		{
			str_to_print = ft_strjoin_mod(str_to_print, buf);
			len++;
		}
		if (buf == '\0')
		{
			write(1, str_to_print, len);
			free(str_to_print);
			str_to_print = NULL;
			len = 0;
		}
		buf = 0;
		bit = 7;
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
