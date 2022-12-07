/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:48:19 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:36:30 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*\*/
int	*get_step(t_data *data)
{
	t_lst	*lstb;
	t_lst	*lsta;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * 500);
	lstb = data->pile_b;
	lsta = data->pile_a;
	i = 0;
	if (!lstb)
		return (NULL);
	while (lstb)
	{
		tab[i] = find_index_andstep(lsta, find_associate(data, lstb->nb))
			+ find_index_andstep(data->pile_b, lstb->nb);
		i++;
		lstb = lstb->next;
	}
	return (tab);
}

int	get_best_move(t_data *data, int *tab, int size)
{
	int		i;
	int		res;
	int		keep;
	t_lst	*tmp;

	keep = 0;
	if (!data->pile_b)
		return (0);
	tmp = data->pile_b;
	res = tab[0];
	i = -1;
	while (++i < size)
		if (res > tab[i])
		{
			res = tab[i];
			keep = i;
		}
	while (keep > 0 && tmp)
	{
		tmp = tmp->next;
		keep--;
	}
	return (tmp->nb);
}

int	find_index(t_lst *lst, int nb)
{
	t_lst	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		if (temp->nb == nb)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

int	smaller(int a, int b)
{
	return (a > b);
}

int	bigger(int a, int b)
{
	return (a < b);
}
/*\*/