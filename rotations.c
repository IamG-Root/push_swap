/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:41 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:41:21 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks, int check)
{
	int	temp;
	int	i;

	if (stacks->sizea >= 2)
	{
		i = 0;
		temp = stacks->stacka[0];
		while (i < stacks->sizea)
		{
			if (i + 1 < stacks->sizea)
				stacks->stacka[i] = stacks->stacka[i + 1];
			i++;
		}
		stacks->stacka[i - 1] = temp;
		if (!check)
			ft_printf("ra\n");
	}
	return ;
}

void	rotate_b(t_stacks *stacks, int check)
{
	int	temp;
	int	i;

	if (stacks->sizeb >= 2)
	{
		i = 0;
		temp = stacks->stackb[0];
		while (i < stacks->sizeb)
		{
			if (i + 1 < stacks->sizeb)
				stacks->stackb[i] = stacks->stackb[i + 1];
			i++;
		}
		stacks->stackb[i - 1] = temp;
		if (!check)
			ft_printf("rb\n");
	}
	return ;
}

void	rotate_r(t_stacks *stacks, int check)
{
	int	temp;
	int	i;

	if (stacks->sizea >= 2 && stacks->sizeb >= 2)
	{
		i = 0;
		temp = stacks->stackb[0];
		while (i < stacks->sizeb)
		{
			if (i + 1 < stacks->sizeb)
				stacks->stackb[i] = stacks->stackb[i + 1];
			i++;
		}
		stacks->stackb[i - 1] = temp;
		i = 0;
		temp = stacks->stacka[0];
		while (++i < stacks->sizea)
			if (i + 1 < stacks->sizea)
				stacks->stacka[i - 1] = stacks->stacka[i];
		stacks->stacka[i - 1] = temp;
		if (!check)
			ft_printf ("rr\n");
	}
}
