/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:36:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:40:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_free(char **args, int count)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (count + 1);
}

int	ft_count(char *s, char c)
{
	int	counter;
	int	pos;

	counter = 0;
	pos = 0;
	while (s[counter])
	{
		if (s[counter] == c && s[counter + 1] != c)
			pos++;
		counter++;
	}
	return (pos + 1);
}

void	ft_push_swap(char **args, int argc, int *a, int *b)
{
	int	count;

	if (argc > 1)
	{
		count = 0;
		while (args[count])
		{
			a[count] = ft_atoi_push(args[count]);
			count++;
		}
		if (argc == 2)
			argc = ft_free(args, count);
		if (ft_checker(argc - 1, a) != 1)
		{
			ft_error(argc - 1, a);
			if (argc == 3)
				ft_swap_a(a);
			if (argc == 4)
				ft_three(argc - 1, a);
			if (argc > 4 && argc < 8)
				ft_five(argc - 1, a, b);
			if (argc > 7)
				ft_hundred(argc - 1, argc - 1, a, b);
		}
	}
}

int	main(int argc, char **argv)
{
	int		count;
	int		*a;
	int		*b;
	char	**args;

	args = NULL;
	count = 0;
	if (argc == 2)
	{
		count = ft_count(argv[1], ' ');
		args = ft_split(argv[1], ' ');
	}
	else if (argc > 2)
	{
		count = argc - 1;
		args = argv;
		args++;
	}
	a = (int *)malloc((count) * sizeof(int));
	b = (int *)ft_calloc((count), sizeof(int));
	ft_push_swap(args, argc, a, b);
	free (b);
	free (a);
	return (0);
}
