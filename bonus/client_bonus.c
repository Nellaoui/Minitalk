/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:27:18 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/29 22:27:30 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int				i;
	unsigned char	*str;
	int				process_id;

	process_id = ft_atoi(av[1]);
	i = 0;
	ft_hundle_pid(process_id);
	if (ac == 3)
	{
		signal(SIGUSR1, ft_complete);
		str = (unsigned char *) av[2];
		while (str[i])
		{
			ft_char_to_binary(process_id, str[i]);
			i++;
		}
		ft_char_to_binary(process_id, '\0');
	}
	else
	{
		ft_printf("ach kat kherb9");
		return (EXIT_FAILURE);
	}
}
