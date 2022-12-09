/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:26:04 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/07 18:33:08 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define A 1
# define B 2
# define AB 3

typedef struct s_lst
{
	int				nb;
	int				index;
	struct s_lst	*next;
}					t_lst;

typedef struct s_data
{
	t_lst			*pile_a;
	t_lst			*pile_b;
	int				asize;
	int				bsize;
	int				tab[501];
	int				big3[4];
	int				size;
	int				indexa;
	int				indexb;
	int				ra;
	int				rb;
}					t_data;

int					push_to_ab(t_lst **pilea, t_lst **pileb, char c);
int					rotate(t_lst **pile, int ab);
void				rotate_ab(t_lst **pilea, t_lst **pileb);
int					revrotate(t_lst **pile, int ab);
void				revrotate_ab(t_lst **pilea, t_lst **pileb);
int					revrotate(t_lst **pile, int ab);
int					my_swap(t_lst **pilea);
t_lst				*my_lstlast(t_lst *lst);
t_lst				*lst_beflast(t_lst *lst);
int					my_lstsize(t_lst *lst);
void				lstrm_front(t_data *data);
int					swap_ss(t_data *data);
void				swap_ab(t_lst *pile, int ab);
t_lst				*fill_pile(char **str);
void				displaylist(t_lst *lst);
int					lstclear(t_data *data);
t_lst				*lstnew(int nb);
void				addback(t_lst **lst, t_lst *new);
long long int		ft_atoilong(const char *str);
int					checkdouble(t_lst *list);
void				trie_igo(t_lst **pilea, t_lst **pileb);
void				algo_troi(t_lst **pilea);
int					find_smaller(t_lst *pile, int f(int a, int b));
void				algo_cinq(t_lst **pilea, t_lst **pileb);
void				algo_tout(t_lst **pilea, t_lst **pileb);
void				lst_totab(t_lst *lst, t_data *data);
void				displaytab(int *tab, int size);
int					return_mediane(t_data *data);
void				algo_100(t_data *data);
int					smaller(int a, int b);
int					bigger(int a, int b);
void				find3big(t_data *data);
void				algo_brutforce(t_data *data);
int					find_int(int *tab, int nb);
void				keep_3big(t_data *data);
void				callrotate_ab(t_data *data, int *ra, int *rb, int dir);
void				callrotate(t_lst **pile, int *ra, char ab, int dir);
void				make_action2(t_data *data);
void				make_action(t_data *data, int nb);
int					find_index(t_lst *lst, int nb);
int					*get_step(t_data *data);
int					get_best_move(t_data *data, int *tab, int size);
int					find_associate(t_data *data, int nb);
int					find_index_andstep(t_lst *lst, int nb);
int					check_sort(t_lst *pile);

#endif
