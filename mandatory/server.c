/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:51 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 15:35:53 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_printf("Num of args is %d and the argument are %s\n", ac, av[1]);
	else
		ft_printf("Incorrect numbers of arguments");
}
