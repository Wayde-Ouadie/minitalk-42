/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:00 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/26 07:01:43 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	error_display(char *str)
{
	ft_fprintf(2, "Error: ");
	ft_fprintf(2, str);
	exit(EXIT_FAILURE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int			i;
	int			tmp;
	long long	res;

	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res * 10 - (48 - str[i++]);
		if (tmp < res)
			error_display("Input valid number");
		res = tmp;
	}
	return (res);
}
