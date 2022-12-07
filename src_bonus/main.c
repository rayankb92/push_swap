/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:19:15 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 23:45:11 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_lst	*fill_pile(char **str)
{
	t_lst			*res;
	int				i;
	long long int	tmp;

	i = 0;
	tmp = ft_atoilong(str[i]);
	res = lstnew(ft_atoilong(str[i]));
	while (str[++i])
	{
		if (tmp > 2147483647 || tmp < -2147483647)
		{
			ft_printf("Int overflow\n");
			lstclear(res);
			return (NULL);
		}
		tmp = ft_atoilong(str[i]);
		addback(&res, lstnew(tmp));
	}
	return (res);
}

// void	my_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = (*lst);
// 	(*lst) = new;
// }

void	lstrm_front(t_data *data)
{
	t_lst	**pilea;
	t_lst	**pileb;
	t_lst	*tmp;

	pilea = &data->pile_a;
	pileb = &data->pile_b;
	tmp = (*pileb);
	(*pileb) = (*pileb)->next;
	tmp->next = (*pilea);
	(*pilea) = tmp;
}

int	check_space(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (((str[i][j] < '0') && (str[i][j] != '+' && str[i][j] != '-'))
				|| (str[i][j] > '9'))
			{
				ft_printf("Error je n'accepte que les chiffres\n");
				return (0);
			}
		}
	}
	return (1);
}

int	check_sort(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp->next)
	{
		if (tmp->nb >= tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	t_data	data;

// 	if (argc < 2)
// 		return (0);
// 	data.pile_a = NULL;
// 	data.pile_b = NULL;
// 	data.pile_a = fill_pile(argv + 1);
// 	if (!data.pile_a || !checkdouble(data.pile_a) || !check_space(argv) || check_sort(data.pile_a))
// 		return (0);
// 	if (my_lstsize(data.pile_a) == 3)
// 		algo_troi(&data.pile_a);
// 	else if (my_lstsize(data.pile_a) == 5)
// 		algo_cinq(&data.pile_a, &data.pile_b);
// 	else
// 		algo_brutforce(&data);
// 	// check_sort(data.pile_a);
// 	return (lstclear(data.pile_a));
// }
