/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:08 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/26 14:39:20 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	parsing(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			ft_fprintf(2, "Error: Input number without sign.");
		else if (!(str[i] >= '0' && str[i] <= '9'))
			ft_fprintf(2, "Error: Input valid number.");
	}
}

static int	ft_atoi(char *str)
{
	int	i;
	int	tmp;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = result * 10 - (48 - str[i++]);
		if (tmp < result)
			ft_fprintf(2, "Error: Input valid number");
		result = tmp;
	}
	return (result);
}

static void	msg_sender(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(800);
	}
}

static void	msg_received(int signal_num)
{
	(void)signal_num;
	ft_fprintf(1, "Message well received.\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		parsing(av[1]);
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			ft_fprintf(2, "Error: Input valid number.");
		if (av[2][0] == '\0')
			ft_fprintf(2, "Error: Empty message.");
		signal(SIGUSR1, msg_received);
		i = -1;
		while (av[2][++i])
			msg_sender(pid, av[2][i]);
		msg_sender(pid, '\n');
		msg_sender(pid, '\0');
	}
	else
	{
		ft_fprintf(2, "Error: Incorrect numbers of arguments.\n");
		ft_fprintf(2, "Example: ./client PID MESSAGE");
	}
}
