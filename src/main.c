/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:19:15 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/08 18:21:51 by rferradi         ###   ########.fr       */
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
	if (tmp > 2147483647 || tmp < -2147483647)
			return (NULL);
	res = lstnew(ft_atoilong(str[i]));
	while (str[++i])
	{
		tmp = ft_atoilong(str[i]);
		if (tmp > 2147483647 || tmp < -2147483647)
			return (NULL);
		addback(&res, lstnew(tmp));
	}
	return (res);
}

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
				return (0);
			if ((str[i][j] == '-' || str[i][j] == '+') && !ft_isdigit(str[i][j
					+ 1]))
				return (0);
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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.pile_a = NULL;
	data.pile_b = NULL;
	data.pile_a = fill_pile(argv + 1);
	if (!data.pile_a || !checkdouble(data.pile_a) || !check_space(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (lstclear(&data));
	}
	if (check_sort(data.pile_a))
		return (lstclear(&data));
	if (my_lstsize(data.pile_a) == 2)
		swap_ab(data.pile_a, 'a');
	else if (my_lstsize(data.pile_a) == 3)
		algo_troi(&data.pile_a);
	else if (my_lstsize(data.pile_a) == 5)
		algo_cinq(&data.pile_a, &data.pile_b);
	else
		algo_brutforce(&data);
	return (lstclear(&data));
}
