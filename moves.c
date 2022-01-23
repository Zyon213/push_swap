/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:07:16 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 18:07:20 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_sa(int *a, int na)
{
	int	temp;

	if (na > 0)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	ft_putstr("sa\n");
	return (a);
}

int	*ft_addfront(int *x, int n, int nx)
{
	int	*xtemp;
	int	i;
	int	j;

	xtemp = malloc(sizeof(int) * nx + 1);
	if (!xtemp)
		exit (0);
	i = 0;
	xtemp[i++] = n;
	j = 0;
	while (j < nx)
		xtemp [i++] = x[j++];
	return (xtemp);
}

int	*ft_removefront(int *x, int nx)
{
	int	*xtemp;
	int	i;
	int	j;

	xtemp = malloc(sizeof(int) * nx - 1);
	if (!xtemp)
		exit (0);
	i = 0;
	j = 1;
	while (j < nx)
		xtemp[i++] = x[j++];
	return (xtemp);
}

int	*ft_rotate(int *x, int nx)
{
	int	*xtemp;
	int	i;
	int	j;
	int	temp;

	xtemp = malloc(sizeof(int) * nx);
	if (!xtemp)
		exit (0);
	j = 0;
	temp = x[j++];
	i = 0;
	while (j < nx)
		xtemp[i++] = x[j++];
	xtemp[i] = temp;
	ft_putstr("ra\n");
	return (xtemp);
}

int	*ft_revrotate(int *x, int nx)
{
	int	temp;
	int	i;
	int	j;
	int	*xtemp;

	xtemp = malloc(sizeof(int) * nx);
	if (!xtemp)
		exit (0);
	i = nx - 1;
	j = nx - 1;
	temp = x[i--];
	while (i >= 0)
		xtemp[j--] = x[i--];
	xtemp[j] = temp;
	ft_putstr("rra\n");
	return (xtemp);
}
