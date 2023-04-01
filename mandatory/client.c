/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:44:32 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/01 01:34:38 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(int process_id, char c)
{
	int	ascii_value;
	int	i;
	int	store[8];

	i = 0;
	ascii_value = (int) c;
	while (i < 8)
	{
		store[i] = ascii_value % 2;
		ascii_value = ascii_value / 2;
		i++;
	}
	i = 7;
	while (i != -1)
	{
		if (store[i] == 0)
			kill(process_id, SIGUSR1);
		else if (store[i] == 1)
			kill(process_id, SIGUSR2);
		usleep(200);
		i--;
	}
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

int	main(int ac, char **av)
{
	int	i;
	int	process_id;

	if (ac == 3)
	{
		i = 0;
		process_id = ft_atoi(av[1]);
		ft_hundle_pid(process_id);
		while (av[2][i])
		{
			char_to_binary(process_id, av[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("NIGGA WHAT ?");
		return (EXIT_FAILURE);
	}
}
