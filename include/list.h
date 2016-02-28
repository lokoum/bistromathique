/*
** list.h for tree in /home/theis_p/Aneo/test_arbre
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct 22 11:46:29 2015 Paul THEIS
** Last update Sun Nov  1 11:47:14 2015 Paul THEIS
*/

#ifndef LIST_H_
# define LIST_H_

# define OP_OPEN_PARENT_IDX 0
# define OP_CLOSE_PARENT_IDX 1
# define OP_ADD_IDX 2
# define OP_SUB_IDX 3
# define OP_NEG_IDX 3
# define OP_MUL_IDX 4
# define OP_DIV_IDX 5
# define OP_MOD_IDX 6

char		*str_to_list(t_info *info, int first, int last);
void		find_first_last(t_info *info, t_stack *stack, int *firster, int *laster);
int		find_operator(t_info *info, int first, int last);
int		count_bracket(t_info *info, int i);
t_node		*eval_list(t_info *info, t_stack **stack, t_node **node);
char		*dup_node(t_info *info, int first, int last);
void		*free_all(t_node *node, t_stack *stack);
t_stack		*add_stack(t_stack *node, int i, int e, int side);
t_node		*add_node(t_node *node, char *str);
char		*stacker(t_info *info, t_stack **stack, t_node **node, int i);
t_node		*rush(t_node *node);
char		*eval_expr(t_info *info, char *n1, char *n2, char op);
char		*my_int_str(int nb, char *s, int *i);
int		is_opp(char c, t_info *info);

#endif /* !LIST_H_ */
