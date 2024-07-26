/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:51 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/26 06:56:28 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	msg_receiver(int signal_num, siginfo_t *info, void *context)
{
	static int		bit;
	static char		c;
	static int		pid;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		bit = 0;
	}
	if (signal_num == SIGUSR1)
		c += (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c != 0)
			ft_fprintf(1, "%c", c);
		else
			kill(pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	(void)av;
	if (ac == 1)
	{
		ft_fprintf(1, "Server PID: %d\n", getpid());
		sig.sa_flags = SA_SIGINFO;
		sig.sa_sigaction = msg_receiver;
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		while (1)
			pause();
	}
	else
		error_display("No arguments Needed. Example use: ./server");
	exit(EXIT_SUCCESS);
}
