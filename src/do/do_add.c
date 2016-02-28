/*
** do_add.c for bistromator in /home/theis_p/bistromator/src/do
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct 19 16:50:46 2015 Paul THEIS
** Last update Sun Nov  1 23:09:07 2015 troncy_l
*/

#include "main.h"

void		do_add2(t_info *info, t_nbr *nbr1, t_nbr *nbr2, t_nbr *res)
{
  int		n1;
  int		n2;

  n1 = 0;
  n2 = 0;
  if (info->var->a < nbr1->len)
    n1 = nbr1->nbr[info->var->a];
  if (info->var->a < nbr2->len)
    n2 = nbr2->nbr[info->var->a];
  n1 += n2 + res->nbr[info->var->a];
  if (n1 >= info->baselen)
    {
      res->nbr[info->var->a + 1] = n1 / info->baselen;
      res->len = info->var->a + 2;
    }
  res->nbr[info->var->a] = n1 % info->baselen;
}

t_nbr		*do_add(t_nbr *nbr1, t_nbr *nbr2, t_info *info)
{
  t_nbr		*res;

  info->var->a = 0;
  if (nbr1->is_neg && !nbr2->is_neg && !(nbr1->is_neg = 0))
    return (do_sub(nbr2, nbr1, info));
  else if (nbr2->is_neg && !nbr1->is_neg && !(nbr2->is_neg = 0))
    return (do_sub(nbr1, nbr2, info));
  if ((res = do_nbr(do_max(nbr1->len, nbr2->len)))== NULL)
    return (NULL);
  while (info->var->a < nbr1->len || info->var->a < nbr2->len)
    {
      do_add2(info, nbr1, nbr2, res);
      ++(info->var->a);
      if (res->len < info->var->a)
	res->len = info->var->a;
    }
  if (nbr1->is_neg && nbr2->is_neg)
    res->is_neg = 1;
  return (res);
}
