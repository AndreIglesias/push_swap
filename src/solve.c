/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:13:58 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/08 10:44:18 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sab(t_pile **p, char *str)
{
	int tmp;
	int tmp2;

	if (*p && (*p)->next)
	{
		ft_putstr(str);
		tmp = (*p)->x;
		tmp2 = (*p)->next->x;
		pop(p);
		pop(p);
		push(p, tmp);
		push(p, tmp2);
	}
	return (1);
}

int		pab(t_pile **p1, t_pile **p2, char *str)
{
	if (*p1)
	{
		ft_putstr(str);
		push(p2, (*p1)->x);
		pop(p1);
	}
	return (1);
}

int		rrab(t_pile **head, char *str)
{
	t_pile	*last_node;
	t_pile	*prev_node;

	if (*head == NULL || (*head)->next == NULL)
		return (1);
	ft_putstr(str);
	last_node = *head;
	prev_node = NULL;
	while (last_node->next)
	{
		prev_node = last_node;
		last_node = last_node->next;
	}
	push(head, last_node->x);
	free(last_node);
	prev_node->next = NULL;
	return (1);
}

int		rab(t_pile **head, char *str)
{
	t_pile	*last_node;

	if (*head == NULL || (*head)->next == NULL)
		return (1);
	ft_putstr(str);
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node((*head)->x, NULL);
	pop(head);
	return (1);
}

void	solve_it(t_pile **pa, t_pile **pb, int ispa, t_pivot v)
{
	int pivot;
	int tmp;

	if (ordered(*pa, 1) && !(*pb))
		return ;
	if (count_between((ispa) ? *pa : *pb, v.min, v.max) > 2)
	{
		pivot = (ispa) ? move_pivot(pa, pb, 1, v) : 0;
		(ispa == 2) ? quick_return(pa, v) : 0;
		pivot = (!ispa) ? move_pivot(pb, pa, 0, v) : pivot;
		tmp = v.max;
		v.max = pivot;
		solve_it(pa, pb, 0, v);
		v.max = tmp;
		v.min = pivot;
		solve_it(pa, pb, 2, v);
	}
	else
	{
		if (pile_len(*pb) > 1 && ((*pb)->x < (*pb)->next->x))
			sab(pb, "sb\n");
		pab(pb, pa, "pa\n");
		if (*pb)
			pab(pb, pa, "pa\n");
	}
}
