/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:46:02 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:46:16 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoilong(const char *str)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i]) && ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	addback(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

t_lst	*lstnew(int nb)
{
	t_lst	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_lst	*my_lstlast(t_lst *lst)
{
	t_lst	*temp;

	temp = lst;
	if (!lst)
		return (lst);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_lst	*lst_beflast(t_lst *lst)
{
	t_lst	*temp;

	temp = lst;
	if (!lst)
		return (0);
	if (temp->next->next == NULL)
		return (temp->next);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}
