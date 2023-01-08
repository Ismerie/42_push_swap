/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:47:28 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/10 18:47:28 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

char	**ft_free_doubletab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(tab[i++]);
	free(tab);
	return (0);
}

int	*ft_free_doubletab2(char **tab, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
		free(tab[i++]);
	free(tab);
	return (0);
}

int	*ft_free_tab(int *stack_a, int *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == '\n' || c == '\f' || c == '\r' || c == '\v'
		|| c == '\t' || c == ' ')
		return (1);
	return (0);
}
