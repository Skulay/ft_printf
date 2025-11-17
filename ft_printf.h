/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:21:35 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/17 03:54:00 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putpointer(void *ptr);

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr(long n);
int ft_puthex(unsigned long n);
int ft_putbighex(unsigned long n);

#endif
