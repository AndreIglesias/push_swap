/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:10:06 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/08 10:22:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** verif.c		: are_num()
** treatment.c	: pile_init()
** solve.c		: other_side()
*/

void	call_alg(t_pile *p1, t_pile *p2)
{
	t_pivot	v;

	v.min = pile_min(p1);
	v.max = pile_max(p1);
	if (ordered(p1, 1))
	{
		free_pile(&p1);
		free_pile(&p2);
		return ;
	}
	if (pile_len(p1) > 5 || pile_len(p1) < 3)
	{
		solve_it(&p1, &p2, 1, v);
		while (p1 && p1->x != v.min)
		{
			if (p1->next && p1->next->x != v.min && p1->next->x < p1->x)
				sab(&p1, "sa\n");
			rab(&p1, "ra\n");
		}
	}
	else
		mini_solve(&p1, &p2);
	free_pile(&p1);
	free_pile(&p2);
}

int		main(int ac, char **av)
{
	t_pile	*p1;
	int		i;
	char	**nbs;

	if (ac > 1)
	{
		p1 = NULL;
		i = 0;
		nbs = &av[1];
		if ((ac == 2))
		{
			nbs = ft_strsplit(av[1], ' ');
			while (nbs[i])
				++i;
			if (!i)
				return (free_split(nbs));
			ac = i + 1;
		}
		if (!valid_input(ac - 1, nbs) || !pile_init(&p1, nbs, ac - 1))
			return (-7 + write(1, "Error\n", 6) + ((i) ? free_split(nbs) : 0));
		if (i)
			free_split(nbs);
		call_alg(p1, NULL);
	}
	return (0);
}
