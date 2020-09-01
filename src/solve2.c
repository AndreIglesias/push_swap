/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 00:17:32 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/08 10:35:15 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_pivot(t_pile **p1, t_pile **p2, int ispa, t_pivot v)
{
	int	pivot;

	pivot = median_between(*p1, v.min, v.max);
	while (*p1 && are_left(*p1, pivot, ispa, v))
	{
		if (ispa)
		{
			if (v.min <= (*p1)->x && (*p1)->x < pivot)
				pab(p1, p2, "pb\n");
			else
				rab(p1, "ra\n");
		}
		else
		{
			if ((*p1)->x >= pivot)
				pab(p1, p2, "pa\n");
			else
				rab(p1, "rb\n");
		}
	}
	return (pivot);
}

void	quick_return(t_pile **p, t_pivot v)
{
	while (last_between(*p, v.min, v.max))
		rrab(p, "rra\n");
}

void	pass_limits(t_pile **pa, t_pile **pb, int i)
{
	int		minpos;
	int		maxpos;
	t_pile	*p;

	p = *pa;
	while (p)
	{
		if (p->x == pile_max(*pa))
			maxpos = i;
		if (p->x == pile_min(*pa))
			minpos = i;
		i++;
		p = p->next;
	}
	i = pile_len(*pa);
	maxpos = (ft_abs(maxpos - i) < maxpos) ? -ft_abs(maxpos - i) : maxpos;
	minpos = (ft_abs(minpos - i) < minpos) ? -ft_abs(minpos - i) : minpos;
	minpos = (ft_abs(minpos) > ft_abs(maxpos)) ? maxpos : minpos;
	while (minpos != 0)
	{
		(minpos < 0) ? rrab(pa, "rra\n") : rab(pa, "ra\n");
		minpos += (minpos < 0) ? 1 : -1;
	}
	pab(pa, pb, "pb\n");
	(pile_len(*pa) == 4) ? pass_limits(pa, pb, 0) : 0;
}

void	insert_pile(t_pile **pa, t_pile **pb)
{
	pab(pb, pa, "pa\n");
	if (ordered(*pa, 1) && (*pb))
		insert_pile(pa, pb);
	else
	{
		if (!ordered(*pa, 1))
			rab(pa, "ra\n");
		if (*pb)
			insert_pile(pa, pb);
	}
}

void	mini_solve(t_pile **pa, t_pile **pb)
{
	int p1;
	int p2;

	if (pile_len(*pa) <= 3)
	{
		p1 = (*pa)->x;
		p2 = (*pa)->next->x;
		if (p1 > p2 || (p1 == pile_min(*pa) && p2 == pile_max(*pa)))
		{
			if (p1 == pile_max(*pa) && p2 == pile_min(*pa))
				rab(pa, "ra\n");
			else
				sab(pa, "sa\n");
		}
		else
			rrab(pa, "rra\n");
		if (!ordered(*pa, 1))
			mini_solve(pa, pb);
		return ;
	}
	pass_limits(pa, pb, 0);
	mini_solve(pa, pb);
	insert_pile(pa, pb);
}
