/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:35:59 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 17:36:04 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '-' || str[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isinrange(long nb)
{
	if (nb <= -2147483648 || nb >= 2147483647)
		return (0);
	return (1);
}

int	ft_isnotdup(int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (num[i] == num[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	big_init(t_bnum *bnum)
{
	bnum->j = 0;
	bnum->t = 0;
	bnum->r = 0;
}
