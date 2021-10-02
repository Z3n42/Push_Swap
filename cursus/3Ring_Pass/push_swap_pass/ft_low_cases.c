/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:48:11 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:38:01 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_three(int argc, int *a)
{
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		ft_swap_a(a);
	if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		ft_swap_a(a);
		ft_reverse_ra(argc, a);
	}
	if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		ft_rotate_a(argc, a);
	if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		ft_swap_a(a);
		ft_rotate_a(argc, a);
	}
	if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		ft_reverse_ra(argc, a);
}

void	ft_five_push(int args, int count, int *a, int*b)
{
	while (count < args)
	{
		ft_push_a(count, a, b);
		count++;
	}
}

void	ft_five(int args, int *a, int *b)
{
	int	count;

	count = args;
	while (count > 3)
	{
		if (ft_mincheck(count, a) < (count / 2))
		{
			while (ft_mincheck(count, a) != 0)
				ft_rotate_a(count, a);
			ft_push_b(count, a, b);
			count--;
		}
		else
		{
			while (ft_mincheck(count, a) != 0)
				ft_reverse_ra(count, a);
			ft_push_b(count, a, b);
			count--;
		}
	}
	ft_three(count, a);
	ft_five_push(args, count, a, b);
}
