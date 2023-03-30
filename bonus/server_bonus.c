/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:27:45 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/29 22:42:00 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_hold_binary(int sig, siginfo_t *info, void *useless)
{
	static int		i;
	static int		elements[16];
	static pid_t	pervious_pid;

	(void) useless;
	if (pervious_pid == 0)
		pervious_pid = info->si_pid;
	if (pervious_pid != info->si_pid)
	{
		pervious_pid = info->si_pid;
		i = 0;
	}
	if (sig == 30)
		elements[i] = 0;
	else
		elements[i] = 1;
	i++;
	if (i == 16)
	{
		ft_printf("%c", ft_binry_to_char(elements));
		if (ft_binry_to_char(elements) == 0)
			kill(info->si_pid, SIGUSR1);
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

	i = 15;
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
	if (decimal_value == 0)
		return (0);
	return (decimal_value);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal_action;

	signal_action.sa_sigaction = ft_hold_binary;
	signal_action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID is : %d\n", pid);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while (1)
		;
	return (0);
}
