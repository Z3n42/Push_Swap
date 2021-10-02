/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:36:21 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/20 20:38:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_chunk_assign(int args, int *chunk, int *temp, int *a)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (count < args)
	{
		j = 0;
		while (j < args)
		{
			if (chunk[count] == a[j])
				temp[j] = count;
			j++;
		}
		count++;
	}
	count = 0;
	while (count < args)
	{
		a[count] = temp[count];
		count++;
	}
	free(temp);
	free(chunk);
}

void	ft_sort_chunk(int size, int *chunk)
{
	int	change;
	int	count;
	int	pos;

	count = 0;
	while (count < size)
	{
		pos = count + 1;
		while (pos < size)
		{
			if (chunk[count] > chunk[pos])
			{
				change = chunk[count];
				chunk[count] = chunk[pos];
				chunk[pos] = change;
			}
			pos++;
		}
		count++;
	}
}

void	ft_chunk(int args, int *a)
{
	int	count;
	int	*chunk;
	int	*temp;

	count = 0;
	chunk = (int *)malloc(args * sizeof(int));
	temp = (int *)malloc(args * sizeof(int));
	while (count < args)
	{
		chunk[count] = a[count];
		count++;
	}
	ft_sort_chunk(args, chunk);
	ft_chunk_assign(args, chunk, temp, a);
}
