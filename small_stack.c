/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:55:36 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/22 19:55:36 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size_three(int *stack_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		ft_swap_sa(stack_a);
	else if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2]
		&& stack_a[1] > stack_a[2])
	{
		ft_swap_sa(stack_a);
		ft_reverse_rotate_rra(stack_a, 3);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2]
		&& stack_a[1] < stack_a[2])
		ft_rotate_ra(stack_a, 3);
	else if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2]
		&& stack_a[1] > stack_a[2])
	{
		ft_swap_sa(stack_a);
		ft_rotate_ra(stack_a, 3);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		ft_reverse_rotate_rra(stack_a, 3);
}

int	sort_small_stack(int *stack, int size)
{
	if (size == 2)
		ft_swap_sa(stack);
	else if (size == 3)
		ft_size_three(stack);
	else if (size == 4)
		stack = ft_size_four(stack);
	else if (size == 5)
		stack = ft_size_five(stack);
	if (!stack)
		return (0);
	free(stack);
	return (1);
}
