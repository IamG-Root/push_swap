/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:21 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:20:47 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks, int check)
{
	int	i;

	if (stacks->sizeb)
	{
		stacks->sizea++;
		i = stacks->sizea;
		while (--i > 0)
			stacks->stacka[i] = stacks->stacka[i - 1];
		stacks->stacka[0] = stacks->stackb[0];
		i = 0;
		stacks->sizeb--;
		while (i < stacks->sizeb)
		{
			stacks->stackb[i] = stacks->stackb[i + 1];
			i++;
		}
		if (!check)
			ft_printf("pa\n");
	}
	return ;
}

void	push_b(t_stacks *stacks, int check)
{
	int	i;

	if (stacks->sizea)
	{
		stacks->sizeb++;
		i = stacks->sizeb;
		while (--i > 0)
			stacks->stackb[i] = stacks->stackb[i - 1];
		stacks->stackb[0] = stacks->stacka[0];
		i = 0;
		stacks->sizea--;
		while (i < stacks->sizea)
		{
			stacks->stacka[i] = stacks->stacka[i + 1];
			i++;
		}
		if (!check)
			ft_printf("pb\n");
	}
	return ;
}
