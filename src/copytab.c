/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copytab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:00:26 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:39:55 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int(int *tab, int size);

void	lst_totab(t_lst *lst, t_data *data)
{
	t_lst		*tmp;
	int			*res;
	int			i;
	int			b;

	i = 0;
	if (!lst)
		return ;
	res = data->tab;
	tmp = lst;
	while (tmp)
	{
		res[i++] = tmp->nb;
		tmp = tmp->next;
	}
	b = i;
	data->size = b;
	sort_int(res, b);
}

void	ft_swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	sort_int(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
