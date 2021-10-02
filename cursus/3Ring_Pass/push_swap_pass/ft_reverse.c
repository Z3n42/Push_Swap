/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:28:17 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:38:35 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_reverse_ra(int argc, int *a)
{
	int	count;
	int	swap;

	swap = a[argc - 1];
	count = argc - 1;
	while (count >= 1)
	{
		a[count] = a[count - 1];
		count--;
	}
	a[0] = swap;
	write(1, "rra\n", 4);
}

void	ft_reverse_rb(int argc, int *b)
{
	int	count;
	int	swap;

	swap = b[argc - 1];
	count = argc - 1;
	while (count >= 1)
	{
		b[count] = b[count - 1];
		count--;
	}
	b[0] = swap;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rr(int argc, int *a, int *b)
{
	int	count;
	int	swap;
	int	swapb;

	swap = a[argc - 2];
	swapb = b[argc - 2];
	count = argc - 2;
	while (count >= 1)
	{
		a[count] = a[count - 1];
		b[count] = b[count - 1];
		count--;
	}
	a[0] = swap;
	b[0] = swapb;
	write(1, "rrr\n", 4);
}
