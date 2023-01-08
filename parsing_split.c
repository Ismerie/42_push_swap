/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:08:00 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 11:31:41 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size_result(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = 1;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_is_space(str[i]) && str[i + 1] && !ft_is_space(str[i + 1]))
			size++;
		i++;
	}
	return (size);
}

static unsigned int	ft_size_str(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i] && !ft_is_space(str[i]))
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_put_str(char *result, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		result[i] = str[i];
		i++;
	}
	*(result + i) = 0;
}

/*split number and space*/
static char	**split_arg(char *str, char **result)
{
	int				i;
	static int		j = 0;

	i = -1;
	while (str[++i])
	{
		if (ft_size_str(str + i) == 0)
			continue ;
		result[j] = malloc((ft_size_str(str + i) + 1) * sizeof(char));
		if (!result[j])
			return (ft_free_doubletab(result, j));
		ft_put_str(result[j], str + i, ft_size_str(str + i));
		i += ft_size_str(str + i) - 1;
		j++;
	}
	return (result);
}

/*create double tab with one number in each sub tab*/
char	**ft_take_arg(char **argv)
{
	int		i;
	int		size;
	char	**first_tab;

	i = -1;
	size = 0;
	while (argv[++i])
		size = size + ft_size_result(argv[i]);
	first_tab = malloc(sizeof(char *) * (size + 1));
	if (!first_tab)
		return (NULL);
	first_tab[size] = NULL;
	i = -1;
	while (argv[++i])
	{	
		first_tab = split_arg(argv[i], first_tab);
		if (!first_tab)
			return (NULL);
	}
	return (first_tab);
}
