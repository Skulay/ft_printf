/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:37:17 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/17 03:56:39 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	check_base(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (!str[i] || !str[i + 1])
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] == '+' || str[i] == '-')
// 			return (0);
// 		j = i + 1;
// 		while (str[j])
// 		{
// 			if (str[i] == str[j])
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// static long int	ft_sign(int nbr)
// {
// 	long int	nbr2;

// 	nbr2 = 0;
// 	nbr2 = nbr;
// 	if (nbr2 < 0)
// 	{
// 		nbr2 *= -1;
// 		ft_putchar_fd('-', 1);
// 	}
// 	return (nbr2);
// }

// void	ft_putnbr_base(unsigned int nbr, char *base)
// {
// 	long int	nb_base;
// 	long int	nbr2;

// 	nb_base = ft_strlen(base);
// 	if (!check_base(base))
// 		return ;
// 	nbr2 = ft_sign(nbr);
// 	if (nbr2 >= nb_base)
// 	{
// 		ft_putnbr_base(nbr2 / nb_base, base);
// 		ft_putnbr_base(nbr2 % nb_base, base);
// 	}
// 	else
// 		ft_putchar_fd(base[nbr2 % nb_base], 1);
// }

int ft_putnbr_unsigned(unsigned int n)
{
	int count = 0;

	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);

	count += ft_putchar((n % 10) + '0');
	return (count);
}

int ft_putpointer(void *ptr)
{
	int count = 0;

	if (!ptr)
		return write(1, "(nil)", 5);

	count += write(1, "0x", 2);
	count += ft_puthex((unsigned long)ptr);
	return count;
}
// POUR LE TESTER
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	ft_putnbr(long n)
{
	int count = 0;

	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

size_t	ft_strlen(long unsigned int s(const char *))
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_puthex(unsigned long n)
{
	int count = 0;
	char *base = "0123456789abcdef";

	if (n >= 16)
		count += ft_puthex(n / 16);
	count += write(1, &base[n % 16], 1);
	return count;
}

int ft_putbighex(unsigned long n)
{
	int count = 0;
	char *base = "0123456789ABCDEF";

	if (n >= 16)
		count += ft_putbighex(n / 16);
	count += write(1, &base[n % 16], 1);
	return count;
}
