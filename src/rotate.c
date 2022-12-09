/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:44:29 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/06 02:28:15 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_lst **pile, int ab)
{
	t_lst	*last;

	if (!*pile || !(*pile)->next)
		return (0);
	last = my_lstlast(*pile);
	last->next = *pile;
	(*pile) = (*pile)->next;
	last->next->next = NULL;
	if (ab == 'a' || ab == 'b')
		ft_printf("r%c\n", ab);
	return (1);
}

int	revrotate(t_lst **pile, int ab)
{
	t_lst	*beflast;
	t_lst	*tmp;

	if (!*pile || my_lstsize(*pile) == 1)
		return (0);
	if (my_lstsize(*pile) == 2)
	{
		ft_printf("rr%c\n", ab);
		return (my_swap(pile));
	}
	beflast = lst_beflast(*pile);
	tmp = beflast->next;
	tmp->next = (*pile);
	(*pile) = tmp;
	beflast->next = NULL;
	if (ab == 'a' || ab == 'b')
		ft_printf("rr%c\n", ab);
	return (1);
}

void	revrotate_ab(t_lst **pilea, t_lst **pileb)
{
	revrotate(pilea, '0');
	revrotate(pileb, '0');
	ft_printf("rrr\n");
}

void	rotate_ab(t_lst **pilea, t_lst **pileb)
{
	rotate(pilea, '0');
	rotate(pileb, '0');
	ft_printf("rr\n");
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
