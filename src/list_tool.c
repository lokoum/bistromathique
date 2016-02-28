/*
** list_tool.c for bistromator in /home/theis_p/Piscine_C_bistromathique
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Sun Nov  1 11:44:03 2015 Paul THEIS
** Last update Sun Nov  1 23:00:46 2015 Paul THEIS
*/

#include "main.h"

int	is_opp(char c, t_info *info)
{
  int	n;

  n = 0;
  while (n < 5)
    {
      if (c ==  info->struc[gl_opptab[n].opp])
        return (n);
      ++n;
    }
  return (n);
}

int	count_bracket(t_info *info, int i)
{
  int	bracket;

  --i;
  bracket = 1;
  while (bracket != 0)
    {
      if (info->expr[i] == info->struc[OP_CLOSE_PARENT_IDX])
        ++bracket;
      if (info->expr[i] == info->struc[OP_OPEN_PARENT_IDX])
        --bracket;
      --i;
    }
  return (i);
}
