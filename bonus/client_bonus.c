/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:27:18 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/28 23:12:00 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(char *str, unsigned char c)
{
	int	ascii_value;
	int	i;
	int	store[16];
	int	procces_id;

	i = 0;
	ascii_value = (int) c;
	procces_id = ft_atoi(str);
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
			kill(procces_id, SIGUSR1);
		else if (store[i] == 1)
			kill(procces_id, SIGUSR2);
		usleep(110);
		i--;
	}
}

void	ft_complete(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("DAKCHI WSL NADI\n");
	exit(0);
}

int	main(int ac, char **av)
{
	int				i;
	unsigned char	*str;

	i = 0;
	signal(SIGUSR1, ft_complete);
	if (ac > 2)
	{
		str = (unsigned char *) av[2];
		while (str[i])
		{
			char_to_binary(av[1], str[i]);
			i++;
		}
	}
	char_to_binary(av[1], '\0');
	if (ac != 2)
		ft_printf("ach kat khwer");
}
