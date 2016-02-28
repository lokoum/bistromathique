/*
** do_sub.c for bistromator in /home/theis_p/bistromator
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct 29 01:33:57 2015 Paul THEIS
** Last update Sun Nov  1 23:13:12 2015 troncy_l
*/

#include "main.h"

void		do_sub2(t_info *info, t_nbr *nbr1, t_nbr *nbr2, t_nbr *res)
{
  int		n1;
  int		n2;

  n1 = 0;
  n2 = 0;
  if (info->var->b < nbr1->len)
    n1 = nbr1->nbr[info->var->b];
  if (info->var->b < nbr2->len)
    n2 = nbr2->nbr[info->var->b];
  n1 -= n2;
  n1 -= res->nbr[info->var->b];
  if (n1 < 0)
    {
      res->nbr[info->var->b + 1] = 1;
      n1 = info->baselen + n1;
    }
  res->nbr[info->var->b] = n1 % info->baselen;
  res->len = info->var->b + 1;
}

t_nbr		*do_sub(t_nbr *nbr1, t_nbr *nbr2, t_info *info)
{
  t_nbr		*res;

  info->var->b = -1;
  if (!nbr1->is_neg && nbr2->is_neg && (nbr2->is_neg = 0) == 0)
    return (do_add(nbr1, nbr2, info));
  if (nbr1->is_neg && !nbr2->is_neg && (nbr2->is_neg = 1) == 1)
    return (do_add(nbr1, nbr2, info));
  if ((res = do_nbr(do_max(nbr1->len, nbr2->len))) == NULL)
    return (NULL);
  if (do_cmp(nbr1, nbr2, info) > 0)
    {
      do_swap(&nbr1, &nbr2);
      res->is_neg = 1;
    }
  while ((info->var->b = info->var->b + 1) < nbr1->len ||
	 info->var->b < nbr2->len)
    do_sub2(info, nbr1, nbr2, res);
  if (nbr1->is_neg && nbr2->is_neg)
    res->is_neg = (!res->is_neg);
  return (res);
}
