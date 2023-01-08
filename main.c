/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:00:13 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/05 15:48:53 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i != (size - 1))
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*stack_a;

	if (argc == 1)
		return (0);
	size = 0;
	stack_a = ft_check_arg(argv + 1, &size);
	if (!stack_a)
		return (ft_error());
	if (a_is_sorted(stack_a, size))
	{
		free(stack_a);
		return (0);
	}
	if (size <= 5)
	{
		if (!sort_small_stack(stack_a, size))
			return (ft_error());
	}
	if (size > 5)
	{
		if (!sort_big_stack(stack_a, size))
			return (ft_error());
	}
	return (0);
}
