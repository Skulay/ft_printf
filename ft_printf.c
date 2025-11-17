/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:47:55 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/17 02:23:50 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	char	*s;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
		if (str[i] == '%' && str[i + 1] == 's')
		{
			s = va_arg(args, char*);
			ft_putstr_fd(s, 1);
		}
		if (str[i] == '%' && str[i + 1] == 'p')
			ft_putpointer(va_arg(args, void*));
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			ft_putnbr_fd(va_arg(args, int), 1);
		if (str[i] == '%' && str[i + 1] == 'u')
			 ft_putnbr_unsigned(va_arg(args, unsigned int));
		if (str[i] == '%' && str[i + 1] == 'x')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
		if (str[i] == '%' && str[i + 1] == 'X')
			ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
		}
		i++;
	}
	return (0);
}

/*

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
• faire une fonction qui regarde les flag present dans le string
• que je pourrais mettre dans les if de ft_printf
• faire une fonction pour chaque flag
*/

