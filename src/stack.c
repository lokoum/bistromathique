/*
** stack.c for stack in /home/theis_p/Aneo/test_arbre
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct 22 10:43:09 2015 Paul THEIS
** Last update Sun Nov  1 22:48:57 2015 troncy_l
*/

#include "main.h"

t_stack		*add_stack(t_stack *stack, int i, int b, int side)
{
  t_stack	*new;

  if ((new = malloc(sizeof(t_stack))) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  if (side == 1)
    {
      new->start = i + 1;
      new->end = b;
    }
  else
    {
      new->start = b;
      new->end = i - 1;
    }
  new->next = NULL;
  new->side = side;
  new->i = i;
  if (stack != NULL)
    stack->next = new;
  new->prev = stack;
  return (new);
}

t_node		*add_node(t_node *node, char *str)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  new->str = str;
  if (node != NULL)
    node->next = new;
  new->prev = node;
  return (new);
}

char		*stacker(t_info *info, t_stack **stack, t_node **node, int i)
{
  t_stack	*new_stack;
  char		*str;
  t_node	*new_node;

  new_stack = *stack;
  new_node = *node;
  if ((new_stack = add_stack(new_stack, i , new_stack->end, 1)) == NULL)
    return (NULL);
  if (i == new_stack->prev->start)
    {
      if ((str = malloc(2)) == NULL)
	perrator(ERROR_MSG, NULL, 0);
      str[0] = info->base[0];
      str[1] = '\0';
      new_node = add_node(new_node, str);
    }
  else
    {
      if ((new_stack = add_stack(new_stack, i, new_stack->prev->start, 0))
	  == NULL)
	return (NULL);
    }
  *stack = new_stack;
  *node = new_node;
  return ("TRUE");
}
