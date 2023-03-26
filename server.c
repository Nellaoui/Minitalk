/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:09:37 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/26 20:46:52 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_hold_binary(int sig)
{
	static int	i;
	static int	elements[8];
	int			decimal_value;

	decimal_value = 0;
	if (sig == 30)
		elements[i] = 0;
	else
		elements[i] = 1;
	i++;
	if (i == 8)
	{
		decimal_value = ft_binry_to_char(elements);
		ft_printf("%c", decimal_value);
		i = 0;
	}
}

int	ft_power(int element, int power)
{
	int	nbr;

	nbr = 1;
	while (power > 0)
	{
		nbr = nbr * element;
		power--;
	}
	return (nbr);
}

int	ft_binry_to_char(int *elements)
{
	int	decimal_value;
	int	i;
	int	j;

	i = 7;
	j = 0;
	decimal_value = 0;
	while (i > 0)
	{
		if (elements[i] == 1)
		{
			decimal_value = decimal_value + ft_power(2, j);
			i--;
			j++;
		}
		else if (elements[i] == 0)
		{
			i--;
			j++;
		}
	}
	return (decimal_value);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("My PID is : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_hold_binary);
		signal(SIGUSR2, ft_hold_binary);
	}
	return (0);
}
