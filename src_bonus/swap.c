/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:54 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:29:48 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_lst *pile, int ab)
{
	int	temp;

	(void)ab;
	if (!pile || !pile->next)
		return ;
	temp = pile->nb;
	pile->nb = pile->next->nb;
	pile->next->nb = temp;
}

int	swap_ss(t_data *data)
{
	swap_ab(data->pile_a, '0');
	swap_ab(data->pile_b, '0');
	return (1);
}
