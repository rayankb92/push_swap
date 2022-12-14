/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:52 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:30:13 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_ab(t_lst **pilea, t_lst **pileb, char c)
{
	t_lst	*tmp;

	(void)c;
	if (!*pilea)
		return (0);
	tmp = (*pilea);
	(*pilea) = (*pilea)->next;
	tmp->next = *pileb;
	(*pileb) = tmp;
	return (0);
}
