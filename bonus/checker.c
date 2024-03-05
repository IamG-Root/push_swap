/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:44:30 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:49:32 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_order(t_stacks *stacks)
{
	if (is_sorted(stacks->stacka, stacks->sizea, 'A') == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	end_program(stacks);
}

void	execute_instruction(t_stacks *stacks, char *instruction)
{
	if (ft_strcmp(instruction, "sa\n"))
		swap_a(stacks, 1);
	else if (ft_strcmp(instruction, "sb\n"))
		swap_b(stacks, 1);
	else if (ft_strcmp(instruction, "ss\n"))
		swap_s(stacks, 1);
	else if (ft_strcmp(instruction, "ra\n"))
		rotate_a(stacks, 1);
	else if (ft_strcmp(instruction, "rb\n"))
		rotate_b(stacks, 1);
	else if (ft_strcmp(instruction, "rr\n"))
		rotate_r(stacks, 1);
	else if (ft_strcmp(instruction, "rra\n"))
		reverse_rotate_a(stacks, 1);
	else if (ft_strcmp(instruction, "rrb\n"))
		reverse_rotate_b(stacks, 1);
	else if (ft_strcmp(instruction, "rrr\n"))
		reverse_rotate_r(stacks, 1);
	else if (ft_strcmp(instruction, "pa\n"))
		push_a(stacks, 1);
	else if (ft_strcmp(instruction, "pb\n"))
		push_b(stacks, 1);
	return ;
}

void	read_instructions(t_stacks *stacks)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		execute_instruction(stacks, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
}

void	start_checker(char **argv)
{
	t_stacks	stacks;
	int			i;
	int			size;

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
	read_instructions(&stacks);
	check_order(&stacks);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
		}
		else
			argv++;
		start_checker(argv);
	}
	return (0);
}
