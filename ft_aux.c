/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:57:29 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 10:43:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_chunkup(int args, int chunk, int *a)
{
	int	count;

	count = 0;
	while (count < args)
	{
		if (a[count] <= chunk)
			return (count);
		count++;
	}
	return (ft_mincheck(args, a));
}

int	ft_chunkdown(int args, int chunk, int *a)
{
	int	count;

	count = args - 1;
	while (count >= 0)
	{
		if (a[count] <= chunk)
			return (count);
		count--;
	}
	return (ft_mincheck(args, a));
}
