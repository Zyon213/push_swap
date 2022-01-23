/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:49:54 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 17:49:57 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_arrsort(int **num, int na)
{
	t_node1	node;
	t_node1	*node1;

	node1 = &node;
	node1->head1 = ft_arrtolink(*num, na);
	node1->b = ft_quicksort(*num, 0, na - 1);
	node1->head2 = ft_arrtolink(node1->b, na);
	while (node1->head2 != NULL)
	{
		if (ft_changeindex(&node1->head1, node1->head2->num,
				node1->head2->index))
		node1->head2 = node1->head2->next;
	}
	ft_pmalloc(&node1->temp, na);
	node1->t = 0;
	while (node1->head1 != NULL)
	{
		node1->temp[node1->t] = node1->head1->index;
		node1->head1 = node1->head1->next;
		node1->t++;
	}
	node1->temp = ft_sort_big(node1->temp, node1->t);
	return (1);
}

int	ft_sort_num(int **num, int j)
{
	t_num	tnum;

	if (ft_sortedint(*num, j))
		return (0);
	else if (j == 2)
		ft_sort_two(*num, j);
	else if (j == 3)
		ft_sort_three(*num, j);
	else if (j == 4)
		ft_sort_four(&tnum, *num, j);
	else if (j == 5)
		ft_sort_five(&tnum, *num, j);
	else if (j > 5)
		ft_arrsort(num, j);
	return (1);
}

int	ft_error(int argc, char **argv)
{
	int	*a;
	int	i;
	int	j;

	i = 1;
	j = 0;
	a = malloc(sizeof(int) * argc - 1);
	while (i < argc)
	{
		a[j] = ft_atoi(argv[i]);
		if (argc < 0 || !ft_isnum(argv[i]) || !ft_isinrange(ft_atol(argv[i])))
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
		j++;
	}
	if (!ft_isnotdup(a, j))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	*ft_intarr(int argc, char **argv)
{
	int	i;
	int	j;
	int	*a;

	a = malloc(sizeof(int) * argc - 1);
	if (!a)
		return (0);
	i = 1;
	j = 0;
	while (i < argc)
		a[j++] = ft_atoi(argv[i++]);
	return (a);
}

int	main(int argc, char **argv)
{
	int	*a;

	if (!ft_error(argc, argv))
		return (0);
	else
	{
		a = ft_intarr(argc, argv);
		ft_sort_num(&a, argc - 1);
	}
	return (0);
}
