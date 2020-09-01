/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:31:13 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/08 10:39:20 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_node(int x, t_pile *next)
{
	t_pile *new;

	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	new->x = x;
	new->next = next;
	return (new);
}

void	print_pile(t_pile *p)
{
	t_pile *current;

	current = p;
	write(1, "<head>[", 7);
	while (current)
	{
		write(1, "  ", 2);
		ft_putnbr(current->x);
		current = current->next;
	}
	write(1, "]<end>\n", 7);
}

void	push(t_pile **head, int val)
{
	t_pile *new;

	new = new_node(val, *head);
	*head = new;
}

void	pop(t_pile **head)
{
	t_pile	*next_node;

	if (*head == NULL)
		return ;
	next_node = (*head)->next;
	free(*head);
	*head = next_node;
}

int		pile_init(t_pile **p, char **nbs, int ac)
{
	while (ac)
	{
		if (islarger(nbs[ac - 1]))
		{
			free_pile(p);
			return (0);
		}
		push(p, ft_atoi(nbs[--ac]));
	}
	return (1);
}
