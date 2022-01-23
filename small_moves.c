/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:48:25 by marvin            #+#    #+#             */
/*   Updated: 2022/01/19 20:48:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pa(t_num *num)
{
	num->num = ft_addfront(num->num, num->temp[0], num->na++);
	num->temp = ft_removefront(num->temp, num->nb--);
	ft_putstr("pa\n");
}

void	ft_pb(t_num *num)
{
	num->temp = ft_addfront(num->temp, num->num[0], num->nb++);
	num->num = ft_removefront(num->num, num->na--);
	ft_putstr("pb\n");
}

void	ft_rot(t_num *num)
{
	num->num = ft_revrotate(num->num, num->na);
	ft_pa(num);
	num->num = ft_rotate(num->num, num->na);
	num->num = ft_rotate(num->num, num->na);
}

void	ft_rot1(t_num *num)
{
	num->num = ft_rotate(num->num, num->na);
	ft_pa(num);
	num->num = ft_revrotate(num->num, num->na);
}

void	ft_fpa(t_num *num)
{
	num->a = ft_addfront(num->a, num->b[0], num->na++);
	num->b = ft_removefront(num->b, num->nb--);
	ft_putstr("pa\n");
}
