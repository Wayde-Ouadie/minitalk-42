/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:08 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 19:33:32 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_fprintf("Num of args is %d and the argument are %s\n", ac, av[1]);
	else
		ft_fprintf("Incorrect numbers of arguments");
}
