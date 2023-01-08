/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:28:28 by igeorge           #+#    #+#             */
/*   Updated: 2022/03/05 15:58:43 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int				ft_error(void);
int				ft_is_space(char c);
char			**ft_free_doubletab(char **tab, int j);
int				*ft_free_doubletab2(char **tab, int *size);
int				*ft_free_tab(int *stack_a, int *stack_b);
int				*ft_check_arg(char **argv, int *size);
char			**ft_take_arg(char **argv);
int				sort_big_stack(int *stack, int size);
int				*tag_stack_a(int *stack, int size);
void			ft_rotate_ra_big(int *stack_a);
void			ft_rotate_ra(int *stack_a, int size);
void			ft_swap_sa(int *stack_a);
void			ft_reverse_rotate_rra(int *stack_a, int size_stack_a);
int				*ft_add_onstack(int *give, int *receive, int push, char *str);
int				*ft_del_onstack(int *stack_give, int size, int count_push);
int				sort_small_stack(int *stack, int size);
int				*ft_size_four(int *stack_a);
int				*ft_push_del(int *stack, int size_stack, char *str);
int				*ft_push_add(int *stack, int size_stack, int element);
int				*ft_size_five(int *stack_a);
void			ft_size_three(int *stack_a);

#endif
