/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:42:12 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/15 09:36:56 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char const *s, char c)
{
	int		k;
	int		trovato;
	int		nwords;

	k = 0;
	trovato = 0;
	nwords = 0;
	while (s[k] != 0)
	{
		if (s[k] != c && trovato == 0)
		{
			nwords = nwords + 1;
			trovato = 1;
		}
		else if (s[k] == c)
			trovato = 0;
		k++;
	}
	return (nwords);
}

static char	*ft_strdupfrom(char const *s, int inizio, int fine)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc (sizeof (char) * (fine - inizio + 1));
	while (inizio < fine)
	{
		newstr[i] = s[inizio];
		inizio++;
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

static char	**ft_dosplit(char **strs, char c, char const *s)
{
	int	k;
	int	j;
	int	inizio;
	int	fine;

	k = 0;
	j = 0;
	while (s[j] != 0)
	{
		if (s[j] != c)
		{
			inizio = j;
			while (s[j] != c && s[j])
				j++;
			fine = j;
			strs[k++] = ft_strdupfrom(s, inizio, fine);
		}
		else if (s[j] == c)
			j++;
	}
	strs[k] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	strs = malloc (sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!s || !strs)
		return (0);
	strs = ft_dosplit(strs, c, s);
	return (strs);
}

int	ps_atoi(char *s, t_stacks *stacks)
{
	int					sign;
	int					i;
	unsigned long int	result;

	sign = 1;
	result = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
			sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			printerror(stacks);
		result = (result * 10) + (s[i] - 48);
		i++;
	}
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		printerror(stacks);
	return (result * sign);
}
