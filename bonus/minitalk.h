/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:30:26 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/29 00:48:04 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include    <unistd.h>
# include    "../printf/ft_printf.h"
# include    <signal.h>

long	ft_atoi(char *str);
void	ft_hold_binary(int sig, siginfo_t *info, void *useless);
void	char_to_binary(char *str, unsigned char c);
int		ft_binry_to_char(int *elements);
int		ft_power(int element, int power);
#endif
