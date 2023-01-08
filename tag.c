/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:47 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/16 19:17:47 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_next_min(int *stack, long min)
{
	int	i;

	i = 0;
	while (stack[i] <= min)
		i++;
	return (stack[i]);
}

static int	ft_put_tag(int *stack_tag, int *stack, long min, int tag)
{
	int	i;

	i = 0;
	while (stack[i] != min)
		i++;
	stack_tag[i] = tag++;
	return (tag);
}

static int	ft_find_min(int *stack, long min, int compare, int i)
{
	if (compare > stack[i] && stack[i] > min)
		compare = stack[i];
	return (compare);
}

/*replace numbers by their index of magnitude in the stack*/
int	*tag_stack_a(int *stack, int size)
{
	int		*stack_tag;
	int		i;
	long	min;
	int		compare;
	int		tag;

	stack_tag = malloc(sizeof(int) * (size + 1));
	if (!stack_tag)
		return (0);
	stack_tag[size] = -1;
	compare = stack[0];
	min = -2147483649;
	tag = 0;
	while (tag != size)
	{
		i = -1;
		while (++i != size)
			compare = ft_find_min(stack, min, compare, i);
		min = compare;
		tag = ft_put_tag(stack_tag, stack, min, tag);
		if (tag != size)
			compare = ft_next_min(stack, min);
	}
	return (stack_tag);
}
