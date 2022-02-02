/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:45:51 by airis             #+#    #+#             */
/*   Updated: 2021/12/16 23:00:26 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "cspdiuxX%"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_sflags(char c);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_int(int numb);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
int		ft_print_uint(unsigned int numb);
char	*ft_utoa(unsigned int n);
int		ft_print_x_and_upx(unsigned int numb, int flag);
int		ft_print_pointer(unsigned long numb);

#endif