/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:57:29 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/23 12:57:29 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sa(int *stack_a)
{
	int	keep;

	ft_printf("sa\n");
	keep = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = keep;
}

void	ft_rotate_ra(int *stack_a, int size_stack_a)
{
	int	i_stack_a;
	int	tmp;

	i_stack_a = 0;
	tmp = stack_a[0];
	while (i_stack_a < size_stack_a - 1)
	{
		stack_a[i_stack_a] = stack_a[i_stack_a + 1];
		i_stack_a++;
	}
	stack_a[i_stack_a] = tmp;
	ft_printf("ra\n");
}

void	ft_reverse_rotate_rra(int *stack_a, int size_stack_a)
{
	unsigned int	i_stack_a;
	int				keep;

	i_stack_a = size_stack_a - 1;
	keep = stack_a[size_stack_a - 1];
	while (i_stack_a > 0)
	{
		stack_a[i_stack_a] = stack_a[i_stack_a - 1];
		i_stack_a--;
	}
	stack_a[i_stack_a] = keep;
	ft_printf("rra\n");
}

int	*ft_push_del(int *stack, int size_stack, char *str)
{
	int	*new_stack;
	int	i_stack;

	ft_printf("%s\n", str);
	if (size_stack == 0 || size_stack == 1)
		return (stack);
	new_stack = malloc(sizeof(int) * (size_stack - 1));
	if (!new_stack)
	{
		free(stack);
		return (0);
	}
	i_stack = 0;
	while (i_stack < size_stack - 1)
	{
		new_stack[i_stack] = stack[i_stack + 1];
		i_stack++;
	}
	free(stack);
	return (new_stack);
}

int	*ft_push_add(int *stack, int size_stack, int element)
{
	int	*new_stack;
	int	i_stack;

	new_stack = malloc(sizeof(int) * (size_stack + 1));
	if (!new_stack)
	{
		free(stack);
		return (0);
	}
	new_stack[0] = element;
	i_stack = 1;
	while (i_stack < size_stack + 1)
	{
		new_stack[i_stack] = stack[i_stack - 1];
		i_stack++;
	}
	free(stack);
	return (new_stack);
}
