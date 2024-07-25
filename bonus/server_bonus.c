/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:18 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 15:35:20 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_printf("Num of args is %d and the argument are %s\n", ac, av[1]);
	else
		ft_printf("Incorrect numbers of arguments");
}
