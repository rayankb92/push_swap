/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:52:14 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:23:17 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_troi(t_lst **pilea)
{
	int	top;
	int	mid;
	int	botom;

	top = (*pilea)->nb;
	mid = (*pilea)->next->nb;
	botom = (*pilea)->next->next->nb;
	if (top < mid && mid > botom && botom > top)
	{
		revrotate(pilea, 'a');
		swap_ab(*pilea, 'a');
	}
	else if (top < mid && mid > botom && botom < top)
		revrotate(pilea, 'a');
	else if (top > mid && mid < botom && botom > top)
		swap_ab(*pilea, 'a');
	else if (top > mid && mid < botom && botom < top)
		rotate(pilea, 'a');
	else if (top > mid && mid > botom)
	{
		rotate(pilea, 'a');
		swap_ab(*pilea, 'a');
	}
}

void	algo_cinq(t_lst **pilea, t_lst **pileb)
{
	int			index;
	int			lstsize;
	static int	count;

	count++;
	lstsize = my_lstsize(*pilea);
	while (lstsize >= 4)
	{
		index = find_smaller(*pilea, &smaller);
		if (index > lstsize / 2)
			while (index++ != lstsize)
				revrotate(pilea, 'a');
		else
			while (index-- != 0)
				rotate(pilea, 'a');
		push_to_ab(pilea, pileb, 'b');
		lstsize--;
	}
	algo_troi(pilea);
	push_to_ab(pileb, pilea, 'a');
	push_to_ab(pileb, pilea, 'a');
}
