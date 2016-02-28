/*
** debugator.c for debugator in /home/theis_p/git/Piscine_C_infinadd
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct 20 21:23:05 2015 Paul THEIS
** Last update Sun Nov  1 23:08:37 2015 Paul THEIS
*/

#include "main.h"

void		debug_stack(t_stack *stack)
{
  my_putstr("#==========\033[32mDEBUGATOR-STACK\033[0m=========#\n");
  if (stack->i)
    debug_put_nbr("i", stack->i);
  if (stack->start)
    debug_put_nbr("start", stack->start);
  if (stack->end)
    debug_put_nbr("end", stack->end);
  if (stack->side)
    debug_put_nbr("side", stack->side);
  if (stack->next)
    debug_putstr("next", "ok");
  if (stack->prev)
    debug_putstr("prev", "ok");
  my_putstr("#==================================#\n");
}

void		debug_node(t_node *node)
{
  my_putstr("#==========\033[32mDEBUGATOR-NODE\033[0m==========#\n");
  if (node->str)
    debug_putstr("str", node->str);
  if (node->i)
    debug_put_nbr("i", node->i);
  if (node->next)
    debug_putstr("next", "ok");
  if (node->prev)
    debug_putstr("prev", "ok");
  my_putstr("#==================================#\n");
}

void		debug_info(t_info *info)
{
  my_putstr("#==========\033[32mDEBUGATOR-INFO\033[0m==========#\n");
  if (info->expr)
    debug_putstr("expr", info->expr);
  if (info->base)
    debug_putstr("base", info->base);
  if (info->struc)
    debug_putstr("structure", info->struc);
  if (info->baselen)
    debug_put_nbr("baselen", info->baselen);
  if (info->size)
    debug_put_nbr("size", info->size);
  if (info->var->a)
    debug_put_nbr("var_a", info->var->a);
  if (info->var->b)
    debug_put_nbr("var_b", info->var->b);
  if (info->var->c)
    debug_put_nbr("var_c", info->var->c);
  if (info->var->d)
    debug_put_nbr("var_d", info->var->d);
  if (info->var->e)
    debug_put_nbr("var_e", info->var->e);
  my_putstr("#==================================#\n");
}

void		debug_nbr(t_nbr *nbr)
{
  my_putstr("#==========\033[32mDEBUGATOR-NBR\033[0m===========#\n");
  if (nbr->nbr)
    debug_putstr_ascii("nbr", nbr->nbr, nbr->len);
  if (nbr->len)
    debug_put_nbr("len", nbr->len);
  if (nbr->is_neg)
    debug_put_nbr("is_neg", nbr->is_neg);
  my_putstr("#==================================#\n");
}
