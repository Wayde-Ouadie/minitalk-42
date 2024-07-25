/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:51 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 21:55:51 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		ft_fprintf(1, "Server PID is %d\n",getpid());
	else
		ft_fprintf(2, "Incorrect numbers of arguments");
	exit(EXIT_SUCCESS);
}
