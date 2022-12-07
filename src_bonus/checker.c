/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:17:15 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/06 18:14:25 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	error(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	checker(t_lst **pile_a, t_lst **pile_b, t_data *data, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		rotate(pile_a, '0');
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(pile_b, '0');
	else if (ft_strcmp(line, "rra\n") == 0)
		revrotate(pile_a, '0');
	else if (ft_strcmp(line, "rrb\n") == 0)
		revrotate(pile_b, '0');
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_ab(pile_a, pile_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		revrotate_ab(pile_a, pile_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		swap_ab(*pile_a, '0');
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_ab(*pile_b, '0');
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_ss(data);
	else if (ft_strcmp(line, "pa\n") == 0)
		push_to_ab(pile_b, pile_a, '0');
	else if (ft_strcmp(line, "pb\n") == 0)
		push_to_ab(pile_a, pile_b, '0');
	else
		return (error("Commande inconnue\n"));
	return (1);
}



int	main(int argc, char *argv[])
{
	t_data data;
	char *line;

	if (argc < 2)
		return (0);
	data.pile_a = NULL;
	data.pile_b = NULL;
	data.pile_a = fill_pile(argv + 1);
	if (!data.pile_a || !checkdouble(data.pile_a) || !check_space(argv) || check_sort(data.pile_a))
		return (0);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!checker(&data.pile_a, &data.pile_b, &data, line))
			return (0);
	}
	if (check_sort(data.pile_a))
		error("\nOK\n");
	else
		ft_printf("\nKO\n");
	return (lstclear(data.pile_a));
}