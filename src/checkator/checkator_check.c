/*
** checkator_check.c for bistromator in /home/theis_p/bistromator
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct 29 14:09:59 2015 Paul THEIS
** Last update Sun Nov  1 23:06:02 2015 Paul THEIS
*/

#include "main.h"

int		check_nbr(t_info *info, int i)
{
  int		n;

  n = 0;
  while (info->base[n] != info->expr[i] && info->base[n] != '\0')
    ++n;
  if (info->base[n] == '\0')
    return (0);
  if (info->expr[i + 1] == info->struc[OP_OPEN_PARENT_IDX])
    return (perrator(SYNTAXE_ERROR_MSG, NULL, 0));
  return (0);
}

int		check_opp2(t_info *info, int i)
{
  if (info->expr[i] == info->struc[OP_ADD_IDX] ||
      info->expr[i] == info->struc[OP_SUB_IDX])
    {
      if (info->expr[i + 1] == info->struc[OP_MUL_IDX] ||
          info->expr[i + 1] == info->struc[OP_DIV_IDX] ||
          info->expr[i + 1] == info->struc[OP_MOD_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i + 1]));
      if (info->expr[i + 1] == info->struc[OP_CLOSE_PARENT_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i + 1]));
      if (info->expr[i + 1] == '\0')
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i]));
    }
  return (0);
}

int		check_opp(t_info *info, int i)
{
  if (check_opp2(info, i) != 0)
    return (1);
  if (info->expr[i] == info->struc[OP_MUL_IDX] ||
      info->expr[i] == info->struc[OP_DIV_IDX] ||
      info->expr[i] == info->struc[OP_MOD_IDX])
    {
      if (info->expr[i + 1] == info->struc[OP_CLOSE_PARENT_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i + 1]));
      if (info->expr[i + 1] == info->struc[OP_MUL_IDX] ||
          info->expr[i + 1] == info->struc[OP_DIV_IDX] ||
          info->expr[i + 1] == info->struc[OP_MOD_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i + 1]));
      if (info->expr[i + 1] == '\0' || i == 0)
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i]));
    }
  return (0);
}

int		check_bracket(t_info *info, int i)
{
  if (info->expr[i] == info->struc[OP_CLOSE_PARENT_IDX])
    {
      if (info->expr[i + 1] != info->struc[OP_ADD_IDX] &&
          info->expr[i + 1] != info->struc[OP_SUB_IDX] &&
          info->expr[i + 1] != info->struc[OP_MUL_IDX] &&
          info->expr[i + 1] != info->struc[OP_DIV_IDX] &&
          info->expr[i + 1] != info->struc[OP_MOD_IDX] &&
          info->expr[i + 1] != info->struc[OP_CLOSE_PARENT_IDX] &&
          info->expr[i + 1] != '\0')
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i]));
      if (info->expr[i + 1] == info->struc[OP_OPEN_PARENT_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i]));
    }
  if (info->expr[i] == info->struc[OP_OPEN_PARENT_IDX])
    {
      if (info->expr[i + 1] == info->struc[OP_CLOSE_PARENT_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i + 1]));
      if (info->expr[i + 1] == info->struc[OP_MUL_IDX] ||
          info->expr[i + 1] == info->struc[OP_DIV_IDX] ||
          info->expr[i + 1] == info->struc[OP_MOD_IDX])
        return (perrator(SYNTAXE_ERROR_MSG, NULL, info->expr[i + 1]));
    }
  return (0);
}

int		check_strucbase(t_info *info, int i)
{
  char		c;

  c = info->expr[i];
  i = 0;
  while (info->base[i] != '\0')
    {
      if (info->base[i] == c)
        return (0);
      ++i;
    }
  i = 0;
  while (info->struc[i] != '\0')
    {
      if (info->struc[i] == c)
        return (0);
      ++i;
    }
  if (c == '\n')
    return (perrator(SYNTAXE_ERROR_MSG, NULL, c));
  return (perrator(SYNTAXE_ERROR_MSG, NULL, c));
}
