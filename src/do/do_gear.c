/*
** do_gear.c for do_gear in /home/theis_p/git/Piscine_C_infinadd
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct 20 14:23:47 2015 Paul THEIS
** Last update Sun Nov  1 23:03:56 2015 troncy_l
*/

#include "main.h"

void			do_swap(t_nbr **nbr1, t_nbr **nbr2)
{
  t_nbr			*swap;

  swap = *nbr1;
  *nbr1 = *nbr2;
  *nbr2 = swap;
}

int			do_cmp(t_nbr *nbr1, t_nbr *nbr2, t_info *info)
{
  int			i;
  int			r;

  info->expr = info->expr;
  if (nbr1->is_neg && !nbr2->is_neg)
    return (1);
  if (nbr1->len != nbr2->len)
    return (nbr2->len - nbr1->len);
  i = nbr1->len;
  while ((i--) > 0)
    {
      r = nbr2->nbr[i] - nbr1->nbr[i];
      if (r != 0)
        return (r);
    }
  return (0);
}

int			do_free_nbr(t_nbr *nbr)
{
  if (nbr == NULL)
    return (1);
  if (nbr->nbr != NULL)
    free(nbr->nbr);
  free(nbr);
  return (0);
}

int			do_free_info(t_info *info)
{
  if (info == NULL)
    return (1);
  if (info->var != NULL)
    free(info->var);
  free(info);
  return (0);
}
