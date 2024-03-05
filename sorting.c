/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:53 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 08:52:46 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_three_a(t_stacks *stacks)
{
	if (stacks->stacka[0] > stacks->stacka[1]
		&&stacks->stacka[0] < stacks->stacka[2])
		swap_a(stacks, 0);
	if (stacks->stacka[0] > stacks->stacka[1]
		&& stacks->stacka[0] > stacks->stacka[2]
		&& stacks->stacka[1] < stacks->stacka[2])
		rotate_a(stacks, 0);
	if (stacks->stacka[0] < stacks->stacka[1]
		&&stacks->stacka[0] < stacks->stacka[2]
		&&stacks->stacka[1] > stacks->stacka[2])
	{
		swap_a(stacks, 0);
		rotate_a(stacks, 0);
	}
	if (stacks->stacka[2] < stacks->stacka[1]
		&&stacks->stacka[2] < stacks->stacka[0]
		&& stacks->stacka[1] > stacks->stacka[0])
		reverse_rotate_a(stacks, 0);
	if (stacks->stacka[0] > stacks->stacka[1]
		&& stacks->stacka[1] > stacks->stacka[2])
	{
		swap_a(stacks, 0);
		reverse_rotate_a(stacks, 0);
	}
	return ;
}

void	case_three_b(t_stacks *stacks, int sizeb)
{
	if (sizeb == 1)
		push_a(stacks, 0);
	else if (sizeb == 2)
	{
		if (stacks->stackb[0] < stacks->stackb[1])
			swap_b(stacks, 0);
		while (sizeb--)
			push_a(stacks, 0);
	}
	else if (sizeb == 3)
	{
		while (sizeb || !(stacks->stacka[0] < stacks->stacka[1]
				&& stacks->stacka[1] < stacks->stacka[2]))
		{
			if (sizeb == 1 && stacks->stacka[0] > stacks->stacka[1])
				swap_a(stacks, 0);
			else if (sizeb == 1
				|| (sizeb >= 2 && stacks->stackb[0] > stacks->stackb[1])
				|| (sizeb == 3 && stacks->stackb[0] > stacks->stackb[2]))
				sizeb = do_push(stacks, sizeb, 'A');
			else
				swap_b(stacks, 0);
		}
	}
	return ;
}

void	case_three_ab(t_stacks *stacks, int sizea)
{
	if (sizea == 3 && stacks->sizea == 3)
		case_three_a(stacks);
	else if (sizea == 2)
	{
		if (stacks->stacka[0] > stacks->stacka[1])
			swap_a(stacks, 0);
	}
	else if (sizea == 3)
	{
		while (sizea != 3 || !(stacks->stacka[0] < stacks->stacka[1]
				&& stacks->stacka[1] < stacks->stacka[2]))
		{
			if (sizea == 3 && stacks->stacka[0] > stacks->stacka[1]
				&& stacks->stacka[2])
				swap_a(stacks, 0);
			else if (sizea == 3 && !(stacks->stacka[2] > stacks->stacka[0]
					&& stacks->stacka[2] > stacks->stacka[1]))
					sizea = do_push(stacks, sizea, 'B');
			else if (stacks->stacka[0] > stacks->stacka[1])
				swap_a(stacks, 0);
			else if (sizea++)
				push_a(stacks, 0);
		}
	}
	return ;
}

int	quicksort_a(t_stacks *stacks, int sizea, int rs)
{
	int	mediane;
	int	numbers;

	if (is_sorted(stacks->stacka, stacks->sizea, 'A') == 1)
		return (1);
	numbers = sizea;
	if (sizea <= 3)
	{
		case_three_ab(stacks, sizea);
		return (1);
	}
	if (!get_mediane(&mediane, stacks->stacka, sizea))
		return (0);
	while (sizea != numbers / 2 + numbers % 2)
	{
		if (stacks->stacka[0] < mediane && (sizea--))
			push_b(stacks, 0);
		else if (++rs)
			rotate_a(stacks, 0);
	}
	while (numbers / 2 + numbers % 2 != stacks->sizea && rs--)
		reverse_rotate_a(stacks, 0);
	return (quicksort_a(stacks, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stacks, numbers / 2, 0));
	return (1);
}

int	quicksort_b(t_stacks *stacks, int sizeb, int rs)
{
	int	mediane;
	int	numbers;

	if (is_sorted(stacks->stackb, stacks->sizeb, 'D') == 1)
		while (sizeb--)
			push_a(stacks, 0);
	if (sizeb <= 3)
	{
		case_three_b(stacks, sizeb);
		return (1);
	}
	numbers = sizeb;
	if (!get_mediane(&mediane, stacks->stackb, sizeb))
		return (0);
	while (sizeb != numbers / 2)
	{
		if (stacks->stackb[0] >= mediane && sizeb--)
			push_a(stacks, 0);
		else if (++rs)
			rotate_b(stacks, 0);
	}
	while (numbers / 2 != stacks->sizeb && rs--)
		reverse_rotate_b(stacks, 0);
	return (quicksort_a(stacks, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stacks, numbers / 2, 0));
}
