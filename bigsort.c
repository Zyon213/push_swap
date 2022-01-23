/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:25:00 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 17:25:06 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*ft_quicksort(int *num, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (num[i] <= num[pivot] && i < last)
				i++;
			while (num[j] > num[pivot])
				j--;
			if (i < j)
				ft_swap(&num[i], &num[j]);
		}
		ft_swap(&num[pivot], &num[j]);
		ft_quicksort(num, first, j - 1);
		ft_quicksort(num, j + 1, last);
	}
	return (num);
}

void	ft_bpb(t_bnum *bnum)
{
	bnum->b = ft_addfront(bnum->b, bnum->a[0], bnum->t);
	bnum->a = ft_removefront(bnum->a, (bnum->n - bnum->t));
	ft_putstr("pb\n");
	bnum->t++;
}

void	ft_bpa(t_bnum *bnum)
{
	bnum->a = ft_addfront(bnum->a, bnum->b[0], bnum->r);
	bnum->b = ft_removefront(bnum->b, bnum->t);
	ft_putstr("pa\n");
	bnum->r++;
	bnum->t--;
}

int	*ft_sort_big(int *a, int n)
{
	t_bnum	bnum;

	bnum.a = a;
	bnum.n = n;
	bnum.i = 0;
	while (bnum.i < 9 && !ft_sortedarr(bnum.a, bnum.n))
	{
		big_init(&bnum);
		while (bnum.j < bnum.n)
		{
			if ((bnum.a[0] >> bnum.i) & 1)
			{
				bnum.a = ft_rotate(bnum.a, (bnum.n - bnum.t));
				bnum.r++;
			}
			else
				ft_bpb(&bnum);
			bnum.j++;
		}
		while (bnum.t > 0)
			ft_bpa(&bnum);
		bnum.i++;
	}
	return (bnum.a);
}
