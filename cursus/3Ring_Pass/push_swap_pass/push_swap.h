/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:25:03 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/21 12:36:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>

void	ft_index(int *chunk, int args, int *a);
void	ft_error(int args, int *c);
void	ft_chunk(int args, int *a);
void	ft_sort_chunk(int size, int *chunk);
int		ft_chunkup(int args, int chunk, int *a);
int		ft_chunkdown(int args, int chunk, int *a);
int		ft_mincheck(int args, int *c);
int		ft_maxcheck(int args, int *c);
int		ft_checker(int argc, int *a);
int		ft_atoi_push(const char *str);
void	ft_swap_a(int *a);
void	ft_swap_b(int *b);
void	ft_swap_ss(int *a, int *b);
void	ft_push_a(int argc, int *a, int *b);
void	ft_push_b(int argc, int *a, int *b);
void	ft_rotate_a(int argc, int *a);
void	ft_rotate_b(int argc, int *b);
void	ft_rotate_rr(int argc, int *a, int *b);
void	ft_reverse_ra(int argc, int *a);
void	ft_reverse_rb(int argc, int *b);
void	ft_reverse_rr(int argc, int *a, int *b);
void	ft_three(int argc, int *a);
void	ft_five(int args, int *a, int *b);
void	ft_hundred(int args, int ln, int *a, int *b);
void	ft_pushtoa(int argb, int *a, int *b);
int		ft_rotup(int count, int chunk, int *a);
int		ft_rotdown(int count, int chunk, int *a);

#endif
