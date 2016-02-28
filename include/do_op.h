/*
** do_op.h for bistromator in /home/theis_p/bistromator
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct 19 20:14:43 2015 Paul THEIS
** Last update Sun Nov  1 20:34:56 2015 troncy_l
*/

#ifndef DO_OP_H_
# define DO_OP_H_

int	do_max(int a, int b);
int	do_nbr_is_zero(t_nbr *nbr);
char	*do_it(char *nbr1, char*nbr2, t_info *info);
t_nbr	*do_nbr(int len);
t_nbr	*do_str_to_nbr(char *str, t_info *info);
char	*do_nbr_to_str(t_nbr *nbr, t_info *info);
int	do_cmp(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
void	do_swap(t_nbr **nbr1, t_nbr **nbr2);
int	do_free_nbr(t_nbr *nbr);
int	do_free_info(t_info *info);
t_nbr	*do_add(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
t_nbr	*do_sub(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
t_nbr	*do_mul(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
t_nbr	*do_div(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
t_nbr	*do_mod(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
char	to_base(int i, t_info *info);
int	from_base(char c, t_info *info);
int	get_operator(t_info *info, int first, int last);
void	get_start_end(t_info *info, t_stack *node, int *firster, int *laster);
int	div_cmp(t_nbr *i, t_nbr *nbr1, int end);
t_nbr	*do_div(t_nbr *nbr1, t_nbr *nbr2, t_info *info);
t_nbr	*do_div2(t_nbr *nbr1, t_nbr *nbr2, t_nbr *res, t_info *info);
t_nbr	*do_mod2(t_nbr *nbr1, t_nbr *nbr2, t_nbr *res, t_info *info);
char	*div_revme(char *str, t_nbr *res);
int	div_isneg(t_nbr *nbr1, t_nbr *nbr2);

#endif /* !DO_OP_H_ */
