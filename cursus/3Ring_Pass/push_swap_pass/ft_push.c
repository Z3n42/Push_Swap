/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:31:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/20 20:32:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push_a(int argc, int *a, int *b)
{
	int	count;

	count = argc - 1;
	while (count >= 1)
	{
		a[count] = a[count - 1];
		count--;
	}
	a[0] = b[0];
	count = 0;
	while (argc > (count + 1))
	{
		b[count] = b[count + 1];
		count++;
	}
	write(1, "pa\n", 3);
}

void	ft_push_b(int argc, int *a, int *b)
{
	int	count;

	count = argc - 1;
	while (count >= 1)
	{
		b[count] = b[count - 1];
		count--;
	}
	b[0] = a[0];
	count = 0;
	while (argc > (count + 1))
	{
		a[count] = a[count + 1];
		count++;
	}
	write(1, "pb\n", 3);
}
