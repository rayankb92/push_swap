/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:56:19 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:46:21 by rferradi         ###   ########.fr       */
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
	if (!list || !list->nb)
		return (0);
	while (tmp)
	{
		tmpj = tmp->next;
		while (tmpj)
		{
			if (tmp->nb == tmpj->nb)
			{
				ft_printf("Il y a 2 nombre identique\n");
				return (0);
			}
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

int	lstclear(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
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
