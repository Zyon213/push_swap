/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:10:08 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 18:10:13 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_sort_two(int *num, int n)
{
	if (n == 2)
	{
		if (num[0] > num[1])
			num = ft_sa(num, n);
	}
	return (num);
}

int	*ft_sort_three(int *num, int n)
{
	if (n == 3)
	{
		while (!ft_sortedint(num, 3))
		{
			if (num[0] < num[1] && num[0] < num[2])
			{
				num = ft_sa(num, n);
				num = ft_rotate(num, n);
			}
			else if (num[0] > num[1] && num[0] < num[2])
				num = ft_sa(num, n);
			else if (num[0] < num[1] && num[0] > num[2])
				num = ft_revrotate(num, n);
			else if (num[0] > num[1] && num[0] > num[2])
			{
				num = ft_rotate(num, n);
			}
			else if (num[0] > num[1] && num[1] < num[2])
				num = ft_rotate(num, n);
		}
	}
	return (num);
}

int	*ft_sort_four(t_num *num, int *a, int n)
{
	num->num = a;
	num->na = n;
	num->nb = 0;
	if (num->na == 4 && !ft_sortedint(num->num, num->na))
		ft_pb(num);
	num->num = ft_sort_three(num->num, num->na);
	if (num->temp[0] < num->num[0])
		ft_pa(num);
	else if (num->temp[0] > num->num[0] && num->temp[0] < num->num[1])
		ft_rot1(num);
	else if (num->temp[0] > num->num[1] && num->temp[0] < num->num[2])
		ft_rot(num);
	else if (num->temp[0] > num->num[2])
	{
		ft_pa(num);
		num->num = ft_rotate(num->num, num->na);
	}
	return (num->num);
}	

void	ft_fpb(t_num *num)
{
	num->b = ft_addfront(num->b, num->a[0], num->nb++);
	num->a = ft_removefront(num->a, num->na--);
	ft_putstr("pb\n");
}

void	ft_sort_five(t_num *num, int *a, int n)
{
	num->a = a;
	num->na = n;
	num->nb = 0;
	if (num->na == 5 && !ft_sortedint(num->a, num->na))
		ft_fpb(num);
	num->a = ft_sort_four(num, num->a, num->na);
	if (num->b[0] < num->a[0])
		ft_putstr("pa\n");
	else if (num->b[0] > num->a[0] && num->b[0] < num->a[1])
		ft_putstr("pa\nsa\n");
	else if (num->b[0] > num->a[1] && num->b[0] < num->a[2])
		ft_putstr("ra\npa\nsa\nrra\n");
	else if (num->b[0] > num->a[2] && num->b[0] < num->a[3])
		ft_putstr("rra\npa\nra\nra\n");
	else if (num->b[0] > num->a[3])
		ft_putstr("pa\nra\n");
}
