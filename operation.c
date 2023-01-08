/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:43:11 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/19 17:43:11 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_add_onstack(int *give, int *receive, int push, char *str)
{
	int	i;
	int	*new_stack;

	new_stack = malloc(sizeof(int) * (push + 1));
	if (!new_stack)
	{
		free(receive);
		return (0);
	}
	new_stack[push] = -1;
	i = 0;
	while (receive[i] != -1)
	{
		new_stack[i + 1] = receive[i];
		i++;
	}
	new_stack[0] = give[0];
	ft_printf("%s\n", str);
	free(receive);
	return (new_stack);
}

int	*ft_del_onstack(int *stack_give, int size, int count_push)
{
	int	i;
	int	*new_stack;

	new_stack = malloc(sizeof(int) * (size - count_push + 1));
	if (!new_stack)
	{
		free(stack_give);
		return (0);
	}
	new_stack[size - count_push] = -1;
	i = 0;
	while (stack_give[i + 1] != -1)
	{
		new_stack[i] = stack_give[i + 1];
		i++;
	}
	free(stack_give);
	return (new_stack);
}

void	ft_rotate_ra_big(int *stack_a)
{
	int	i;
	int	keep;

	i = 0;
	keep = stack_a[0];
	while (stack_a[i + 1] != -1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = keep;
	ft_printf("ra\n");
}
