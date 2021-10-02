/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:26:36 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:39:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate_a(int argc, int *a)
{
	int	count;
	int	swap;

	swap = a[0];
	count = 0;
	while (count < (argc - 1))
	{
		a[count] = a[count + 1];
		count++;
	}
	a[argc - 1] = swap;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(int argc, int *b)
{
	int	count;
	int	swap;

	swap = b[0];
	count = 0;
	while (count < (argc - 1))
	{
		b[count] = b[count + 1];
		count++;
	}
	b[argc - 1] = swap;
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(int argc, int *a, int *b)
{
	int	count;
	int	swap;

	swap = a[0];
	count = 0;
	while (count < (argc - 1))
	{
		a[count] = a[count + 1];
		count++;
	}
	a[argc - 1] = swap;
	swap = b[0];
	count = 0;
	while (count < (argc - 1))
	{
		b[count] = b[count + 1];
		count++;
	}
	b[argc - 1] = swap;
	write(1, "rr\n", 3);
}
