/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:52 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/05 20:34:02 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_ab(t_lst **pilea, t_lst **pileb, char c)
{
	t_lst	*tmp;

	if (!*pilea)
		return (0);
	tmp = (*pilea);
	(*pilea) = (*pilea)->next;
	tmp->next = *pileb;
	(*pileb) = tmp;
	ft_printf("p%c\n", c);
	return (0);
}
