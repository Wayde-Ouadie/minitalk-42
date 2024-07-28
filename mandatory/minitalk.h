/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:44 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/28 10:43:08 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void    error(char *err_msg);
int		ft_fprintf(int fd, const char *format, ...);
#endif