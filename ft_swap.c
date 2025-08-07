/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:25:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:39:35 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap_a(int *a)
{
	int	swap;

	swap = a[0];
	a[0] = a[1];
	a[1] = swap;
	write(1, "sa\n", 3);
}

void	ft_swap_b(int *b)
{
	int	swap;

	swap = b[0];
	b[0] = b[1];
	b[1] = swap;
	write(1, "sb\n", 3);
}

void	ft_swap_ss(int *a, int *b)
{
	int	swap;

	swap = a[0];
	a[0] = a[1];
	a[1] = swap;
	swap = b[0];
	b[0] = b[1];
	b[1] = swap;
	write(1, "ss\n", 3);
}
