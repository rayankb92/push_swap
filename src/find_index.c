/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:38:14 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:24:44 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller(t_lst *pile, int f(int a, int b))
{
	int		nb;
	int		i;
	t_lst	*tmp;
	int		j;

	tmp = pile;
	i = 0;
	j = 0;
	nb = tmp->nb;
	while (tmp)
	{
		if (f(nb, tmp->nb))
		{
			nb = tmp->nb;
			j = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (j);
}

void	find3big(t_data *data)
{
	int	size;

	size = my_lstsize(data->pile_a);
	lst_totab(data->pile_a, data);
	data->big3[0] = data->tab[size - 1];
	data->big3[1] = data->tab[size - 2];
	data->big3[2] = data->tab[size - 3];
	data->big3[3] = data->tab[0];
}

int	find_int(int *tab, int nb)
{
	int	i;

	i = 0;
	while (i < 3)
		if (tab[i++] == nb)
			return (1);
	return (0);
}

int	find_index_andstep(t_lst *lst, int nb)
{
	t_lst	*tmp;
	int		i;
	int		step;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->nb == nb)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i < my_lstsize(lst) / 2)
		step = i;
	else
		step = my_lstsize(lst) - i;
	return (step);
}

int	find_associate(t_data *data, int nb)
{
	t_lst	*atmp;
	int		associate;

	associate = data->big3[0];
	atmp = data->pile_a;
	while (atmp)
	{
		if (atmp->nb > nb && atmp->nb < associate)
			associate = atmp->nb;
		atmp = atmp->next;
	}
	return (associate);
}
