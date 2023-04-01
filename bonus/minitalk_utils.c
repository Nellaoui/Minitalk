/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:29:52 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/31 21:33:32 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	ft_atoi(char *str)
{
	long	signe;
	long	i;
	long	result;

	signe = 1;
	i = 0;
	result = 0;
	if (str[i] == '-')
	{
		signe = signe * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
	{
		printf("ach katkherb");
		exit(EXIT_FAILURE);
	}
	return (result * signe);
}

void	ft_hundle_pid(int process_id)
{
	if (process_id <= 0)
	{
		ft_printf("pid rah ghalt");
		exit (EXIT_FAILURE);
	}
	if (kill(process_id, 0) == -1)
	{
		ft_printf("pid rah ghalt");
		exit (EXIT_FAILURE);
	}
}

void	ft_complete(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("DAKCHI WSL NADI\n");
	exit(EXIT_SUCCESS);
}

void	ft_char_to_binary(int process_id, unsigned char c)
{
	int	ascii_value;
	int	i;
	int	store[16];

	i = 0;
	ascii_value = (int) c;
	while (i < 16)
	{
		store[i] = ascii_value % 2;
		ascii_value = ascii_value / 2;
		i++;
	}
	i = 15;
	while (i != -1)
	{
		if (store[i] == 0)
			kill(process_id, SIGUSR1);
		else if (store[i] == 1)
			kill(process_id, SIGUSR2);
		usleep(110);
		i--;
	}
}
