/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:08 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:17:52 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stacks(t_stacks *stacks)
{
	if (is_sorted(stacks->stacka, stacks->sizea, 'A') == 0)
	{
		if (stacks->sizea == 2)
			swap_a(stacks, 0);
		else if (stacks->sizea == 3)
			case_three_a(stacks);
		else
			quicksort_a(stacks, stacks->sizea, 0);
	}
	return (0);
}

void	start_program(char **argv)
{
	t_stacks	stacks;
	int			size;
	int			i;

	i = 0;
	size = arglen(argv);
	stacks.stacka = (int *)malloc(sizeof(int) * size);
	if (!stacks.stacka)
		return ;
	stacks.sizea = size;
	stacks.stackb = (int *)malloc(sizeof(int) * size);
	if (!stacks.stackb)
	{
		free(stacks.stacka);
		return ;
	}
	stacks.sizeb = 0;
	while (i < size)
	{
		stacks.stacka[i] = ps_atoi(argv[i], &stacks);
		i++;
	}
	checkdoubles(&stacks);
	sort_stacks(&stacks);
	end_program(&stacks);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		start_program(argv);
	}
	return (0);
}
