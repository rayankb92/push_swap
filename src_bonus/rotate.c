/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:44:29 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:29:33 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_lst **pile, int ab)
{
	t_lst	*last;

	(void)ab;
	if (!*pile || !(*pile)->next)
		return (0);
	last = my_lstlast(*pile);
	last->next = *pile;
	(*pile) = (*pile)->next;
	last->next->next = NULL;
	return (1);
}

int	revrotate(t_lst **pile, int ab)
{
	t_lst	*beflast;
	t_lst	*tmp;

	(void)ab;
	if (!*pile || my_lstsize(*pile) == 1)
		return (0);
	if (my_lstsize(*pile) == 2)
		return (my_swap(pile));
	beflast = lst_beflast(*pile);
	tmp = beflast->next;
	tmp->next = (*pile);
	(*pile) = tmp;
	beflast->next = NULL;
	return (1);
}

void	revrotate_ab(t_lst **pilea, t_lst **pileb)
{
	revrotate(pilea, '0');
	revrotate(pileb, '0');
}

void	rotate_ab(t_lst **pilea, t_lst **pileb)
{
	rotate(pilea, '0');
	rotate(pileb, '0');
}

int	my_swap(t_lst **pilea)
{
	t_lst	*last;
	int		tmp;

	last = (*pilea)->next;
	tmp = (*pilea)->nb;
	(*pilea)->nb = last->nb;
	last->nb = tmp;
	return (1);
}
