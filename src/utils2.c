/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:56:19 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:25:30 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_lstsize(t_lst *lst)
{
	t_lst	*verif;
	int		i;

	i = 0;
	verif = lst;
	while (verif)
	{
		verif = verif->next;
		i++;
	}
	return (i);
}

int	checkdouble(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*tmpj;

	tmp = list;
	while (tmp)
	{
		tmpj = tmp->next;
		while (tmpj)
		{
			if (tmp->nb == tmpj->nb)
				return (0);
			tmpj = tmpj->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	displaylist(t_lst *lst)
{
	t_lst	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		ft_printf("maillon %i = %i\n", i, temp->nb);
		temp = temp->next;
		i++;
	}
}

int	lstclear(t_data *data)
{
	t_lst	*tmp;

	while (data->pile_a)
	{
		tmp = data->pile_a->next;
		free(data->pile_a);
		data->pile_a = tmp;
	}
	while (data->pile_b)
	{
		tmp = data->pile_b->next;
		free(data->pile_b);
		data->pile_b = tmp;
	}
	return (0);
}

void	displaytab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("| %i |----|%i\n", tab[i], i);
		i++;
	}
}
