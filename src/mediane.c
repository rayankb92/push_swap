/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:31:07 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:31:33 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*\*/
int	return_mediane(t_data *data)
{
	int	lsize;

	lst_totab(data->pile_a, data);
	lsize = my_lstsize(data->pile_a);
	return (data->tab[lsize / 2]);
	return (-1);
}

void	sort_b(t_data *data)
{
	int	lstsize;
	int	indexbig;

	lstsize = my_lstsize(data->pile_b);
	while (lstsize > 1)
	{
		lstsize = my_lstsize(data->pile_b);
		indexbig = find_smaller(data->pile_b, &bigger);
		if (indexbig < lstsize / 2)
			while (indexbig != 0)
			{
				rotate(&data->pile_b, 'b');
				indexbig--;
			}
		else if (indexbig >= lstsize / 2)
			while (indexbig < lstsize)
			{
				revrotate(&data->pile_b, 'b');
				indexbig++;
			}
		push_to_ab(&data->pile_b, &data->pile_a, 'a');
	}
}

void	presort_b(t_data *data)
{
	t_lst	*last;
	int		indexbig;
	int		lstsize;

	last = lst_beflast(data->pile_a);
	last = last->next;
	indexbig = find_smaller(data->pile_b, &bigger);
	lstsize = my_lstsize(data->pile_b);
	if (indexbig < lstsize / 2)
		rotate_ab(&data->pile_a, &data->pile_b);
	else
		rotate(&data->pile_a, 'a');
}

void	algo_100(t_data *data)
{
	int	mediane;

	mediane = return_mediane(data);
	while (my_lstsize(data->pile_a) > 3)
	{
		if (data->pile_a->nb > mediane)
		{
			if (my_lstsize(data->pile_b) > 2)
				presort_b(data);
			else
				rotate(&data->pile_a, 'a');
		}
		else
		{
			push_to_ab(&data->pile_a, &data->pile_b, 'b');
			mediane = return_mediane(data);
		}
	}
	algo_troi(&data->pile_a);
}

/*\*/