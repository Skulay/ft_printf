/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:37:17 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/17 02:26:25 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

static int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str[i] || !str[i + 1])
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static long int	ft_sign(int nbr)
{
	long int	nbr2;

	nbr2 = 0;
	nbr2 = nbr;
	if (nbr2 < 0)
	{
		nbr2 *= -1;
		ft_putchar_fd('-', 1);
	}
	return (nbr2);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb_base;
	long int	nbr2;

	nb_base = ft_strlen(base);
	if (!check_base(base))
		return ;
	nbr2 = ft_sign(nbr);
	if (nbr2 >= nb_base)
	{
		ft_putnbr_base(nbr2 / nb_base, base);
		ft_putnbr_base(nbr2 % nb_base, base);
	}
	else
		ft_putchar_fd(base[nbr2 % nb_base], 1);
}

void ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

void ft_putpointer(void *ptr)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
}
