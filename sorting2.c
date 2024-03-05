/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:42:00 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:29:27 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_push(t_stacks *stacks, int size, char type)
{
	if (type == 'A')
		push_a(stacks, 0);
	else if (type == 'B')
		push_b(stacks, 0);
	size--;
	return (size);
}

void	brutesort(int *sorted, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		if (sorted[i] > sorted[i + 1] && i + 1 < size)
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return ;
}

int	get_mediane(int *mediane, int *stack, int size)
{
	int	*sorted;
	int	i;

	i = 0;
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (i < size)
	{
		sorted[i] = stack[i];
		i++;
	}
	brutesort(sorted, size);
	*mediane = sorted[size / 2];
	free(sorted);
	return (1);
}

int	is_sorted(int *stack, int size, char order)
{
	int	i;

	i = 0;
	if (order == 'A')
	{
		while (i < size)
		{
			if (stack[i] > stack[i + 1] && i + 1 < size)
				return (0);
			i++;
		}
		return (1);
	}
	else if (order == 'D')
	{
		while (i < size)
		{
			if (stack[i] < stack[i + 1] && i + 1 < size)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
