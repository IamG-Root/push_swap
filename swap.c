/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:42:22 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:43:55 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks, int check)
{
	int	temp;

	if (stacks->sizea >= 2)
	{
		temp = stacks->stacka[0];
		stacks->stacka[0] = stacks->stacka[1];
		stacks->stacka[1] = temp;
		if (!check)
			ft_printf("sa\n");
	}
	return ;
}

void	swap_b(t_stacks *stacks, int check)
{
	int	temp;

	if (stacks->sizeb >= 2)
	{
		temp = stacks->stackb[0];
		stacks->stackb[0] = stacks->stackb[1];
		stacks->stackb[1] = temp;
		if (!check)
			ft_printf("sb\n");
	}
	return ;
}

void	swap_s(t_stacks *stacks, int check)
{
	int	temp;

	if (stacks->sizea >= 2 && stacks->sizeb >= 2)
	{
		temp = stacks->stackb[0];
		stacks->stackb[0] = stacks->stackb[1];
		stacks->stackb[1] = temp;
		temp = stacks->stacka[0];
		stacks->stacka[0] = stacks->stacka[1];
		stacks->stacka[1] = temp;
		if (!check)
			ft_printf("ss\n");
	}
	return ;
}
