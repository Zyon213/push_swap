/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:44:51 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 17:44:55 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_pmalloc(int **a, int n)
{
	*a = malloc(sizeof(int) * n);
	if (!*a)
		return (0);
	return (*a);
}

int	ft_sortedarr(int *num, int n)
{
	int	i;

	i = 0;
	while (i < (n -1))
	{
		if (num[i] > num[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_addlink(t_node **node, int num, int index)
{
	t_node	*current;
	t_node	*root;

	current = malloc(sizeof(t_node));
	if (!current)
		exit (0);
	current->num = num;
	current->index = index;
	current->next = NULL;
	if (*node == NULL)
		*node = current;
	else
	{
		root = *node;
		while (root->next != NULL)
			root = root->next;
		root->next = current;
	}
}

t_node	*ft_arrtolink(int *num, int n)
{
	t_node	*root;
	int		i;

	root = NULL;
	i = 0;
	while (i < n)
	{
		ft_addlink(&root, num[i], i);
		i++;
	}
	return (root);
}

int	ft_changeindex(t_node **node, int num, int index)
{
	t_node	*root;

	root = *node;
	while (root != NULL)
	{
		if (root->num == num)
		{
			root->index = index;
			return (1);
		}
		root = root->next;
	}
	return (0);
}
