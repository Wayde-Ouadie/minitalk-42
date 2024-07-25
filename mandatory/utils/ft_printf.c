/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:25 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 15:35:28 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_putchar(char c, int *size)
{
	(*size)++;
	write(1, &c, 1);
}

static void	ft_putnbr(int nbr, int *size)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar('-', size);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, size);
		ft_putchar((n % 10) + 48, size);
	}
	else
		ft_putchar(n + 48, size);
}

static void	ft_putstr(char *str, int *size)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", size);
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], size);
}

static void	ft_recognition(va_list args, const char format, int *size)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), size);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), size);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), size);
	else
		ft_putchar(format, size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	int		i;
	va_list	args;

	if (write(1, "", 0) == -1)
		return (-1);
	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			ft_recognition(args, format[i], &size);
		}
		else
			ft_putchar(format[i], &size);
		i++;
	}
	va_end(args);
	return (size);
}
