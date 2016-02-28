/*
** base.c for base in /home/theis_p/git/Piscine_C_infinadd
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct 20 13:56:20 2015 Paul THEIS
** Last update Sun Nov  1 23:00:27 2015 troncy_l
*/

#include "main.h"

char	to_base(int i, t_info *info)
{
  return (info->base[i]);
}

int	from_base(char c, t_info *info)
{
  int	i;

  i = 0;
  while (i < info->baselen)
    {
      if (info->base[i] == c)
        return (i);
      ++i;
    }
  return (0);
}
