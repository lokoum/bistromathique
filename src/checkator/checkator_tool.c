/*
** checkator_tool.c for tool in /home/theis_p/bistromator
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct 29 15:39:22 2015 Paul THEIS
** Last update Sun Nov  1 23:06:46 2015 Paul THEIS
*/

#include "main.h"

int		countbracket(int bracket, t_info *info, int i)
{
  if (info->expr[i] == info->struc[OP_OPEN_PARENT_IDX])
    ++bracket;
  else if (info->expr[i] == info->struc[OP_CLOSE_PARENT_IDX])
    --bracket;
  return (bracket);
}

int		next_check(t_info *info, int i)
{
  if (check_strucbase(info, i) != 0)
    return (1);
  if ((info->expr[i] == info->struc[OP_OPEN_PARENT_IDX] ||
       info->expr[i] == info->struc[OP_CLOSE_PARENT_IDX]) &&
      check_bracket(info, i) != 0)
    return (1);
  if (check_opp(info, i) != 0)
    return (1);
  if (check_nbr(info, i) != 0)
    return (1);
  return (0);
}

int		checkator_syntax(t_info *info)
{
  int           bracket;
  int		i;

  bracket = 0;
  i = 0;
  while (i < info->size)
    {
      if ((next_check(info, i)) != 0)
        return (1);
      if ((bracket = countbracket(bracket, info, i)) < 0)
        return (perrator(SYNTAXE_ERROR_MSG, NULL, 0));
      ++i;
    }
  if (bracket != 0)
    return (perrator(SYNTAXE_ERROR_MSG, NULL, 0));
  return (0);
}
