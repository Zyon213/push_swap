/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:17:15 by yonas             #+#    #+#             */
/*   Updated: 2022/01/04 18:17:18 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				num;
	int				index;
	struct t_node	*next;
}	t_node;

typedef struct t_node1
{
	struct t_node	*head1;
	struct t_node	*head2;
	int				*temp;
	int				*num;
	int				*b;
	int				t;
}	t_node1;

typedef struct t_num
{
	int	*num;
	int	*a;
	int	*b;
	int	*temp;
	int	n;
	int	na;
	int	nb;
}	t_num;

typedef struct t_bnum
{
	int	*a;
	int	*b;
	int	n;
	int	i;
	int	j;
	int	t;
	int	r;
}	t_bnum;

int		*ft_sort_two(int *num, int n);
int		*ft_sort_three(int *num, int n);
int		*ft_sa(int *a, int na);
int		*ft_addfront(int *x, int n, int nx);
int		*ft_removefront(int *x, int nx);
int		*ft_rotate(int *x, int nx);
int		*ft_revrotate(int *x, int nx);
int		ft_isnum(char *str);
int		ft_isinrange(long nb);
int		ft_isnotdup(int *num, int size);
int		*ft_quicksort(int *num, int first, int last);
int		*ft_sort_big(int *a, int n);
int		ft_sortedarr(int *num, int n);
void	ft_addlink(t_node **node, int num, int index);
t_node	*ft_arrtolink(int *num, int n);
int		ft_changeindex(t_node **node, int num, int index);
int		*ft_malloc(int *num, int size);
void	ft_putstr(char *str);
int		ft_sortedint(int *num, int n);
int		ft_atoi(char *str);
long	ft_atol(char *str);
int		*ft_pmalloc(int **a, int n);
int		*ft_sort_four(t_num *num, int *a, int n);
void	ft_pb(t_num *num);
void	ft_pa(t_num *num);
void	ft_rot(t_num *num);
void	ft_rot1(t_num *num);
void	ft_sort_five(t_num *tnum, int *a, int n);
void	ft_fpa(t_num *num);
void	ft_fpb(t_num *num);
void	ft_bpb(t_bnum *bnum);
void	ft_bpa(t_bnum *bnum);
void	big_init(t_bnum *bnum);

#endif