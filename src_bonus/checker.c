/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:17:15 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:27:21 by rferradi         ###   ########.fr       */
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
		return (error("Error\n"));
	return (1);
}

void	check_entries(char **argv, int argc, t_data *data)
{
	if (argc < 2)
		exit(0);
	data->pile_a = fill_pile(argv + 1, data);
	if (!data->pile_a || !checkdouble(data->pile_a) || !check_space(argv))
	{
		ft_putstr_fd("Error\n", 2);
		lstclear(data);
		exit(1);
	}
	data->size = my_lstsize(data->pile_a);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*line;

	check_entries(argv, argc, &data);
	while (1)
	{
		line = get_next_line(0, 1);
		if (!line)
			break ;
		if (!checker(&data.pile_a, &data.pile_b, &data, line))
		{
			free(line);
			get_next_line(0, 0);
			return (lstclear(&data));
		}
		free(line);
	}
	if (check_sort(data.pile_a) && (my_lstsize(data.pile_a) == data.size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (lstclear(&data));
}
