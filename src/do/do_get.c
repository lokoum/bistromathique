/*
** find.c for find in /home/theis_p/Aneo/test_arbre
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct 22 14:53:55 2015 Paul THEIS
** Last update Sun Nov  1 23:07:28 2015 troncy_l
*/

#include "main.h"

void		get_start_end(t_info *info, t_stack *stack, int *starter,
				int *ender)
{
  int		start;
  int		end;

  start = stack->start;
  end = stack->end;
  while (info->expr[end] == info->struc[OP_CLOSE_PARENT_IDX]
	 && count_bracket(info, end) == start - 1)
    {
      ++start;
      --end;
    }
  stack->start = start;
  stack->end = end;
  *starter = start;
  *ender = end;
}

int		get_operator(t_info *info, int start, int end)
{
  int		op;
  int		i;

  i = end + 1;
  op = -1;
  while ((--i) >= start)
    {
      if (info->expr[i] == info->struc[OP_CLOSE_PARENT_IDX])
        i = count_bracket(info, i);
      if (i < start)
        return (op);
      if ((info->expr[i] == info->struc[OP_ADD_IDX] ||
           info->expr[i] == info->struc[OP_SUB_IDX]) &&
	  (i - 1 < start || ((info->expr[i - 1] != info->struc[OP_ADD_IDX] &&
			      info->expr[i - 1] != info->struc[OP_SUB_IDX] &&
			      info->expr[i - 1] != info->struc[OP_MUL_IDX] &&
			      info->expr[i - 1] != info->struc[OP_DIV_IDX] &&
			      info->expr[i - 1] != info->struc[OP_MOD_IDX]))))
        return (i);
      if (op == -1 && (info->expr[i] == info->struc[OP_MUL_IDX] ||
                       info->expr[i] == info->struc[OP_DIV_IDX] ||
                       info->expr[i] == info->struc[OP_MOD_IDX]))
        op = i;
    }
  return (op);
}

t_node		*rush(t_node *node)
{
  node = node->prev->prev;
  free(node->next->next->str);
  free(node->next->next);
  free(node->next->str);
  free(node->next);
  return (node);
}
