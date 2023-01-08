/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:27:52 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/05 15:58:34 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicate(int	*tab, int size)
{
	int	i;
	int	compare;

	i = 0;
	compare = 1;
	while (i < size - 1)
	{
		while (compare < size)
		{
			if (tab[i] == tab[compare])
				return (0);
			compare++;
		}
		i++;
		compare = i + 1;
	}
	return (1);
}

static long	ft_atoi_long(char *str)
{
	int					i;
	long				nbr;
	int					negative;

	i = 0;
	nbr = 0;
	negative = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i++] - '0');
	}
	if (negative == 1)
		nbr = -nbr;
	return (nbr);
}

static int	ft_check_str(char	*tab)
{
	int	i;

	if (!(tab[0] == '-' || tab[0] == '+' || ft_isdigit(tab[0])))
		return (0);
	i = 1;
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	*ft_create_stack_a(char **tab, int *size)
{
	int		i;
	int		*stack_a;
	long	number;

	stack_a = malloc(sizeof(int) * (*size));
	if (!stack_a)
		return (0);
	i = 0;
	while (tab[i])
	{
		if (!ft_check_str(tab[i]))
			return (ft_free_tab(stack_a, 0));
		number = ft_atoi_long(tab[i]);
		if (number > 2147483647 || number < -2147483648)
			return (ft_free_tab(stack_a, 0));
		stack_a[i] = (int)number;
		i++;
	}
	return (stack_a);
}

/*create stack_A and check number*/
int	*ft_check_arg(char **argv, int *size)
{
	int		i;
	char	**first_tab;
	int		*stack_a;

	first_tab = ft_take_arg(argv);
	if (!first_tab)
		return (0);
	i = -1;
	while (first_tab[++i])
		*size = *size + 1;
	stack_a = ft_create_stack_a(first_tab, size);
	ft_free_doubletab2(first_tab, size);
	if (!stack_a)
		return (0);
	if (!ft_check_duplicate(stack_a, *size))
		return (ft_free_tab(stack_a, 0));
	return (stack_a);
}
