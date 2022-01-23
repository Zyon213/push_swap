/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:37:42 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 17:37:47 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_malloc(int *num, int size)
{
	num = malloc(sizeof(int) * size);
	if (num == NULL)
		exit (0);
	return (num);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_sortedint(int *num, int n)
{
	int	i;

	i = 0;
	while (i < (n - 1))
	{
		if (num[i] > num[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == ' '))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

long	ft_atol(char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == ' '))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}
