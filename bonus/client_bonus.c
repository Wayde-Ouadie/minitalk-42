/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:08 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/26 07:07:51 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	parsing(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			error_display("Input number without sign.");
		else if (!(str[i] >= '0' && str[i] <= '9'))
			error_display("Input valid number.");
	}
}

static void	send_bits(int pid, char b)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (b & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(800);
	}
}

static void	msg_sender(int pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		send_bits(pid, msg[i]);
	send_bits(pid, '\0');
}

static void	msg_received(int signal_num)
{
	(void)signal_num;
	ft_fprintf(1, "Message well received.\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		parsing(av[1]);
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			error_display("Input valid number.");
		if (av[2][0] == '\0')
			error_display("Empty message.");
		signal(SIGUSR1, msg_received);
		msg_sender(pid, av[2]);
	}
	else
		ft_fprintf(2, "Incorrect numbers of arguments.");
}
