/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:44:32 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/23 01:51:59 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(char *str, char c)
{
	int	ascii_value;
	int	i;
	int	store[8];
	int	procces_id;

	porcess_id = ft_atoi(str);
	i = 0;
	ascii_value = (int) c;
	while (i < 8)
	{
		store[i] = ascii_value % 2;
		ascii_value = ascii_value / 2;
	}
	i = 0;
	while (i != 8)
	{
		if (store[i] == 0)
			kill(procces_id, SIGUSR1);
		if (store[i] == 1)
			kill(procces_id, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;

	si
	if (ac > 2)
	{
		while (av[2][i])
		{
			char_to_binary(av[1], av[2][i]);
			i++;
		}
	}
	else
		ft_printf("NIGGA WHAT ?");
}
