/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:33 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:34:46 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks, int check)
{
	int	temp;
	int	i;

	if (stacks->sizea >= 2)
	{
		i = stacks->sizea - 1;
		temp = stacks->stacka[i];
		while (i >= 0)
		{
			if (i - 1 >= 0)
				stacks->stacka[i] = stacks->stacka[i - 1];
			i--;
		}
		stacks->stacka[0] = temp;
		if (!check)
			ft_printf("rra\n");
	}
	return ;
}

void	reverse_rotate_b(t_stacks *stacks, int check)
{
	int	temp;
	int	i;

	if (stacks->sizeb >= 2)
	{
		i = stacks->sizeb - 1;
		temp = stacks->stackb[i];
		while (i >= 0)
		{
			if (i - 1 >= 0)
				stacks->stackb[i] = stacks->stackb[i - 1];
			i--;
		}
		stacks->stackb[0] = temp;
		if (!check)
			ft_printf("rrb\n");
	}
	return ;
}

void	reverse_rotate_r(t_stacks *stacks, int check)
{
	int	temp;
	int	i;

	if (stacks->sizeb >= 2 && stacks->sizea >= 2)
	{
		i = stacks->sizea - 1;
		temp = stacks->stacka[i];
		while (i >= 0)
		{
			if (i - 1 >= 0)
				stacks->stacka[i] = stacks->stacka[i - 1];
			i--;
		}
		stacks->stacka[0] = temp;
		i = stacks->sizeb - 1;
		temp = stacks->stackb[i];
		while (i--)
			if (i - 1 >= 0)
				stacks->stackb[i] = stacks->stackb[i - 1];
		stacks->stackb[0] = temp;
		if (!check)
			ft_printf("rrr\n");
	}
}
