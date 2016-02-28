/*
** aff_tree.c for bistromator in /home/theis_p/bistromator
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Sat Oct 31 21:27:29 2015 Paul THEIS
** Last update Sun Nov  1 23:04:06 2015 Paul THEIS
*/

#include "main.h"

void	aff_stack(t_stack *stack)
{
  if (!stack)
    return;
  debug_stack(stack);
  if (stack->next)
    aff_stack(stack->next);
}

void	aff_node(t_node *node)
{
  if (!node)
    return;
  debug_node(node);
  if (node->next)
    aff_node(node->next);
}
