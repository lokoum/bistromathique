/*
** list.c for bistromator in /home/theis_p/Piscine_C_bistromathique
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Sun Nov  1 13:23:25 2015 Paul THEIS
** Last update Sun Nov  1 23:03:34 2015 Paul THEIS
*/

#include "main.h"
#include "s_opp.h"

char		*evalexpr(t_info *info, char *nbr1, char *nbr2, char op)
{
 char		*str;
  t_nbr		*res;
  t_nbr		*n1;
  t_nbr		*n2;
  int		rst;

  if ((n1 = do_str_to_nbr(nbr1, info)) == NULL)
    return (NULL);
  if ((n2 = do_str_to_nbr(nbr2, info)) == NULL)
    return (NULL);
  res = NULL;
  rst = is_opp(op, info);
  res = gl_opptab[rst].do_this(n1, n2, info);
  str = do_nbr_to_str(res, info);
  if (res != n1 && res != NULL)
    do_free_nbr(res);
  do_free_nbr(n1);
  do_free_nbr(n2);
  return (str);
}

t_node		*eval_list(t_info *info, t_stack **stack, t_node **node)
{
  t_stack	*stacky;
  t_stack	*stack_prev;
  char		*str;
  t_node	*nodey;

  stacky = *stack;
  if ((str = dup_node(info, stacky->start, stacky->end)) == NULL)
    return (NULL);
  if ((nodey = add_node((nodey = *node), str)) == NULL)
    return (NULL);
  while (stacky->side == 1)
    {
      str = evalexpr(info, nodey->prev->str, nodey->str, info->expr[stacky->i]);
      if (str == NULL)
	return (free_all(nodey, stacky));
      if ((nodey = add_node((nodey = rush(nodey)), str)) == NULL)
	return (NULL);
      if ((stack_prev = stacky->prev)->next != NULL)
	free(stacky);
      stacky = stack_prev;
    }
  *stack = stacky->prev;
  if (stacky != NULL)
    free(stacky);
  return (nodey);
}

char		*dup_node(t_info *info, int start, int end)
{
  char		*str;
  int		i;

  i = 0;
  while (info->expr[start] == info->struc[0])
    {
      ++start;
      --end;
    }
  while (info->expr[start] == info->base[0] && start < end)
    ++start;
  if ((str = malloc(end - start + 2)) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  while (start + i < end + 1)
    {
      str[i] = info->expr[start + i];
      ++i;
    }
  str[i] = '\0';
  return (str);
}

char		*str_to_list(t_info *info, int start, int end)
{
  t_stack	*stack;
  t_node	*node;
  char		*str;
  int		i;

  if ((stack = add_stack(NULL, 0, start, 0)) == NULL)
    return (NULL);
  stack->end = end;
  if ((node = add_node(NULL, NULL)) == NULL)
    return (NULL);
  while (stack != NULL)
    {
      get_start_end(info, stack, &start, &end);
      if ((i = get_operator(info, start, end)) == -1)
	node = eval_list(info, &stack, &node);
      else
	str = stacker(info, &stack, &node, i);
      if (node == NULL)
	return (NULL);
    }
  str = node->str;
  free(node->prev);
  free(node);
  return (str);
}

void		*free_all(t_node *node, t_stack *stack)
{
  t_node	*tmp_node;
  t_stack	*tmp_stack;

  while (node != NULL)
    {
      tmp_node = node->prev;
      if (node->str != NULL)
	free(node->str);
      free(node);
      node = tmp_node;
    }
  while (stack != NULL)
    {
      tmp_stack = stack->prev;
      free(stack);
      stack = tmp_stack;
    }
  return (NULL);
}
