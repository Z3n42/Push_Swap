/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:07:26 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:36:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_integer(const char *str)
{
	long	in;
	int		Max;
	int		Min;

	in = 0;
	Max = 2147483647;
	Min = -2147483648;
	while (*str > 47 && *str < 58 )
	{
		in = (in * 10) + (*str - '0');
		str++;
	}
	if ((*str && (*str < 48 || *str > 57)) || ((in > Max) || (in < Min)))
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	return (in);
}

int	ft_atoi_push(const char *str)
{
	int		minus;
	int		plus;
	long	integer;

	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	minus = 0;
	plus = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		plus++;
		str++;
	}
	if (minus > 1 || plus > 1)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	integer = ft_integer(str);
	if ((minus % 2) != 0)
		integer = integer * (-1);
	return (integer);
}
