/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:00:58 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/15 20:00:58 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*push_all(int *stack_a, int *stack_b, int nbr_push, int new_size_a)
{
	int	i;

	i = 1;
	while (i <= nbr_push)
	{
		stack_a = ft_add_onstack(stack_b, stack_a, ++new_size_a, "pa");
		if (!stack_a)
			return (ft_free_tab(stack_b, 0));
		stack_b = ft_del_onstack(stack_b, nbr_push, i);
		if (!stack_b)
			return (ft_free_tab(stack_a, 0));
		i++;
	}
	free (stack_b);
	return (stack_a);
}

static int	*ft_sort_bit(int *stack_a, int *stack_b, int size, int i_bit)
{
	int	i;
	int	count_push;

	i = 0;
	count_push = 0;
	while (i < size)
	{
		if ((stack_a[0] >> i_bit) & 1)
			ft_rotate_ra_big(stack_a);
		else
		{
			stack_b = ft_add_onstack(stack_a, stack_b, ++count_push, "pb");
			if (!stack_b)
				return (ft_free_tab(stack_a, 0));
			stack_a = ft_del_onstack(stack_a, size, count_push);
			if (!stack_a)
				return (ft_free_tab(stack_b, 0));
		}
		i++;
	}
	return (push_all(stack_a, stack_b, count_push, size - count_push));
}

static int	ft_resolve(int *stack_a, int size, int max_bit)
{
	int	i;
	int	*stack_b;

	i = 0;
	while (i < max_bit)
	{
		stack_b = malloc(sizeof(int) * 1);
		if (!stack_b)
		{
			free(stack_a);
			return (0);
		}
		stack_b[0] = -1;
		stack_a = ft_sort_bit(stack_a, stack_b, size, i);
		if (!stack_a)
			return (0);
		i++;
	}
	free(stack_a);
	return (1);
}

static int	ft_max_bit(int max)
{
	int	i;

	i = 0;
	while (max >> i != 0)
		i++;
	return (i);
}

int	sort_big_stack(int *stack, int size)
{
	int	*stack_a;
	int	max_bit;

	stack_a = tag_stack_a(stack, size);
	free(stack);
	if (!stack_a)
		return (0);
	max_bit = ft_max_bit(size - 1);
	if (!ft_resolve(stack_a, size, max_bit))
		return (0);
	return (1);
}
