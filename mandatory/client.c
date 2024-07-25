/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:36 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 21:58:46 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	parsing(char *str)
{
	int i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			error_display("Input number without sign");
		else if (!(str[i] >= '0' && str[i] <= '9'))
			error_display("Input valid number");
	}
}

static void	msg_sender(int pid, char *msg)
{
	
}

int	main(int ac, char **av)
{
	int		pid;
	int		len;

	if (ac == 3)
	{
		parsing(av[1]);
		pid = ft_atoi(av[1]);
		if (pid == 0)
			error_display("Input valid number");
		len = ft_strlen(av[2]);
		if (av[2] == NULL || av[2][0] == '\0')
			error_display("Empty message");
		msg_sender(pid, av[2]);
	}
	else
		ft_fprintf(2, "Incorrect numbers of arguments");
}
