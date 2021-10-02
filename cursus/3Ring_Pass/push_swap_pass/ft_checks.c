/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:51:42 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/20 20:55:21 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_error(int args, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < args)
	{
		while (j < args)
		{
			if (c[i] == c[j])
			{
				write(1, "ERROR\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_mincheck(int args, int *c)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 1;
	min = 0;
	while (i < (args))
	{
		while (j < (args))
		{
			if ((c[i] < c[j]) && (c[i] < c[min]))
				min = i;
			j++;
		}
		i++;
		j = 0;
	}
	return (min);
}

int	ft_maxcheck(int args, int *c)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 1;
	max = 0;
	while (i < (args))
	{
		while (j < (args))
		{
			if ((c[i] > c[j]) && (c[i] > c[max]))
				max = i;
			j++;
		}
		i++;
		j = 0;
	}
	return (max);
}

int	ft_checker(int argc, int *a)
{
	int	count;
	int	less;

	count = 0;
	less = 0;
	while (count < (argc - 1))
	{
		if (a[count] < a[count + 1])
			less++;
		count++;
	}
	if (less == (argc - 1))
		return (1);
	else
		return (0);
}
