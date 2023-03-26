/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:21:01 by nelallao          #+#    #+#             */
/*   Updated: 2023/03/23 23:12:32 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main()
{
int elements[8] = {0,1,1,1,0,0,0,0};

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
			decimal_value = decimal_value + 0;
			i--;
			j++;
		}
	}
	printf("%d\n", i);
	printf("%d", decimal_value);
}
