/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:50:09 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:52:50 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_stacks
{
	int	*stacka;
	int	*stackb;
	int	sizea;
	int	sizeb;
}	t_stacks;

int		arglen(char **argv);
char	**ft_split(const char *a, char c);
void	printerror(t_stacks *stacks);
int		ps_atoi(char *s, t_stacks *stacks);
void	checkdoubles(t_stacks *stacks);
int		ft_strcmp(char *s1, char *s2);
void	end_program(t_stacks *stacks);
int		sort_stacks(t_stacks *stacks);
int		is_sorted(int *stack, int size, char order);
void	brutesort(int *sorted, int size);
void	push_a(t_stacks *stacks, int check);
void	push_b(t_stacks *stacks, int check);
void	swap_a(t_stacks *stacks, int check);
void	swap_b(t_stacks *stacks, int check);
void	swap_s(t_stacks *stacks, int check);
void	rotate_a(t_stacks *stacks, int check);
void	rotate_b(t_stacks *stacks, int check);
void	rotate_r(t_stacks *stacks, int check);
void	reverse_rotate_a(t_stacks *stacks, int check);
void	reverse_rotate_b(t_stacks *stacks, int check);
void	reverse_rotate_r(t_stacks *stacks, int check);
void	case_three_a(t_stacks *stacks);
void	case_three_b(t_stacks *stacks, int sizeb);
void	case_three_ab(t_stacks *stacks, int sizea);
int		get_mediane(int *mediane, int *stack, int size);
int		quicksort_a(t_stacks *stacka, int sizea, int rs);
int		quicksort_b(t_stacks *stacks, int sizeb, int rs);
int		do_push(t_stacks *stacks, int size, char type);
#endif
