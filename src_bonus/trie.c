/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:54:17 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:38:32 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_3big(t_data *data)
{
	int	size;

	size = my_lstsize(data->pile_a);
	find3big(data);
	while (size > 3)
	{
		if (!find_int(data->big3, data->pile_a->nb))
		{
			push_to_ab(&data->pile_a, &data->pile_b, 'b');
			size--;
		}
		else
			rotate(&data->pile_a, 'a');
	}
}

void	algo_brutforce(t_data *data)
{
	int		*tab;
	int		bestmove;
	int		lsize;
	int		ind;

	find3big(data);
	algo_100(data);
	lsize = my_lstsize(data->pile_b);
	while (lsize >= 1)
	{
		tab = get_step(data);
		bestmove = get_best_move(data, tab, lsize--);
		make_action(data, bestmove);
		free(tab);
	}
	lsize = my_lstsize(data->pile_a);
	ind = find_index(data->pile_a, data->big3[3]);
	if (ind < lsize / 2)
	{
		while (data->pile_a->nb != data->big3[3])
			rotate(&data->pile_a, 'a');
	}
	else
		while (data->pile_a->nb != data->big3[3])
			revrotate(&data->pile_a, 'a');
}
