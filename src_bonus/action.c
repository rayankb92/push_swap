/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:53:32 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:25:51 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	callrotate_ab(t_data *data, int *ra, int *rb, int dir)
{
	if (dir == 1)
		rotate_ab(&data->pile_a, &data->pile_b);
	else
		revrotate_ab(&data->pile_a, &data->pile_b);
	(*ra)--;
	(*rb)--;
}

void	callrotate(t_lst **pile, int *ra, char ab, int dir)
{
	if (dir == 1)
		rotate(pile, ab);
	else
		revrotate(pile, ab);
	(*ra)--;
}

void	make_action2(t_data *data)
{
	if (data->indexa < data->asize / 2)
	{
		if ((data->indexb < data->bsize / 2))
			while (data->ra > 0 && data->rb > 0)
				callrotate_ab(data, &data->ra, &data->rb, 1);
		while (data->ra > 0)
			callrotate(&data->pile_a, &data->ra, 'a', 1);
	}
	else
	{
		if (data->indexb >= data->bsize / 2)
			while (data->ra > 0 && data->rb > 0)
				callrotate_ab(data, &data->ra, &data->rb, -1);
		while (data->ra > 0)
			callrotate(&data->pile_a, &data->ra, 'a', -1);
	}
}

void	make_action(t_data *data, int nb)
{
	data->indexa = find_index(data->pile_a, find_associate(data, nb));
	data->indexb = find_index(data->pile_b, nb);
	data->asize = my_lstsize(data->pile_a);
	data->bsize = my_lstsize(data->pile_b);
	data->ra = find_index_andstep(data->pile_a, find_associate(data, nb));
	data->rb = find_index_andstep(data->pile_b, nb);
	make_action2(data);
	if (data->indexb < data->bsize / 2)
	{
		if (data->indexa < data->asize / 2)
			while (data->rb > 0 && data->ra > 0)
				callrotate_ab(data, &data->ra, &data->rb, 1);
		while (data->rb > 0)
			callrotate(&data->pile_b, &data->rb, 'b', 1);
	}
	else
	{
		if (data->indexa >= data->asize / 2)
			while (data->rb > 0 && data->ra > 0)
				callrotate_ab(data, &data->ra, &data->rb, -1);
		while (data->rb > 0)
			callrotate(&data->pile_b, &data->rb, 'b', -1);
	}
	push_to_ab(&data->pile_b, &data->pile_a, 'a');
}
