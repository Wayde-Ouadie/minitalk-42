/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:35:44 by oel-feng          #+#    #+#             */
/*   Updated: 2024/07/25 19:51:36 by oel-feng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int     ft_atoi(char *str);
int	    ft_strlen(char *str);
void    error_display(char *str);
int     ft_fprintf(int fd, const char *format, ...);
#endif