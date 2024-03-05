/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:42:31 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:23:59 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_program(t_stacks *stacks)
{
	free(stacks->stacka);
	free(stacks->stackb);
	exit(0);
}

void	printerror(t_stacks *stacks)
{
	ft_printf("Error\n");
	end_program(stacks);
}

int	arglen(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	checkdoubles(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->sizea)
	{
		j = i + 1;
		while (j < stacks->sizea)
		{
			if (stacks->stacka[i] == stacks->stacka[j])
				printerror(stacks);
			j++;
		}
		i++;
	}
	return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
