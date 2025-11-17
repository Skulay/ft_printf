/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:47:55 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/17 03:53:41 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	char	*s;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
			count += ft_putchar_fd(va_arg(args, int), 1);
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			s = va_arg(args, char*);
			count += ft_putstr_fd(s, 1);
		}
		else if (str[i] == '%' && str[i + 1] == 'p')
			count += ft_putpointer(va_arg(args, void*));
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			count += ft_putnbr(va_arg(args, int));
		else if (str[i] == '%' && str[i + 1] == 'u')
			 count += ft_putnbr_unsigned(va_arg(args, unsigned int));
		else if (str[i] == '%' && str[i + 1] == 'x')
			count += ft_puthex(va_arg(args, unsigned int));
		else if (str[i] == '%' && str[i + 1] == 'X')
			count += ft_putbighex(va_arg(args, unsigned int));
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			count += ft_putchar_fd('%', 1);
			i++;
		}
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
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

