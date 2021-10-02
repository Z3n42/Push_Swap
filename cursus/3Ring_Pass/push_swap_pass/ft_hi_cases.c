/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hi_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:49:46 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/20 21:15:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_pushtoa(int argb, int *a, int *b)
{
	while (argb >= 0)
	{
		if (ft_maxcheck(argb, b) <= (argb / 2))
		{
			while (ft_maxcheck(argb, b) != 0)
			{
				if ((ft_maxcheck(argb, b) == 1) && (b[0] < b[1]))
					ft_swap_b(b);
				else
					ft_rotate_b(argb, b);
			}
			ft_push_a(argb, a, b);
			argb--;
		}
		else
		{
			while (ft_maxcheck(argb, b) != 0)
				ft_reverse_rb(argb, b);
			ft_push_a(argb, a, b);
			argb--;
		}
	}
}

int	ft_rotup(int count, int chunk, int *a)
{
	int	up;

	up = ft_chunkup(count, chunk, a);
	while (up != 0 && (a[0] > chunk))
		ft_rotate_a(count, a);
	count--;
	return (count);
}

int	ft_rotdown(int count, int chunk, int *a)
{
	int	down;

	down = ft_chunkdown(count, chunk, a);
	while (down != 0 && (a[0] > chunk))
		ft_reverse_ra(count, a);
	count--;
	return (count);
}

int	ft_len(int pos, int ln)
{
	if (ln == 200)
		pos = ln / 8;
	if (ln == 100)
		pos = ln / 6;
	if (ln == 20)
		pos = ln / 3;
	if (ln == 10)
		pos = ln / 2;
	return (pos);
}

void	ft_hundred(int args, int ln, int *a, int *b)
{
	int	chunk;
	int	pos;

	pos = args / 6;
	if (args > 100)
		pos = args / 12;
	chunk = pos;
	ft_chunk(args, a);
	while (ln > 0)
	{
		if (ft_chunkup(ln, chunk, a) <= (ln + 1 - ft_chunkdown(ln, chunk, a)))
		{
			ln = ft_rotup(ln, chunk, a);
			ft_push_b(args, a, b);
		}
		else
		{
			ln = ft_rotdown(ln, chunk, a);
			ft_push_b(args, a, b);
		}
		pos = ft_len(pos, ln);
		if (ln <= args - chunk)
			chunk += pos;
	}
	ft_pushtoa(args, a, b);
}
