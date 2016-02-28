/*
** multi_inf for multiINFI in /home/troncy_l/prog/rendu/modulo_inf
** 
** Made by troncy_l
** Login   <troncy_l@epitech.net>
** 
** Started on  Mon Oct 26 16:06:33 2015 troncy_l
** Last update Sun Nov  1 23:11:25 2015 troncy_l
*/

#include "main.h"

int		res_is_neg(t_nbr *nbr1, t_nbr *nbr2)
{
  int		neg;

  neg = (nbr1->is_neg != nbr2->is_neg) ? (1) : (0);
  nbr1->is_neg = 0;
  nbr2->is_neg = 0;
  return (neg);
}

t_nbr		*do_mul2(t_info *info, t_nbr *nbr1, t_nbr *nbr2, t_nbr *tmp)
{
  int		n;

  n = tmp->nbr[info->var->c + info->var->d];
  n += (int)nbr1->nbr[info->var->d] * (int)nbr2->nbr[info->var->c];
  if (n >= info->baselen)
    {
      tmp->nbr[info->var->c + info->var->d + 1] = n / info->baselen;
      tmp->len = info->var->c + info->var->d + 2;
    }
  tmp->nbr[info->var->c + info->var->d] = n % info->baselen;
  if (tmp->len < info->var->c + info->var->d + 1)
    tmp->len = info->var->c + info->var->d + 1;
  return (tmp);
}

t_nbr		*do_mul(t_nbr *nbr1, t_nbr *nbr2, t_info *info)
{
  t_nbr		*res;
  t_nbr		*tmp;

  info->var->c = -1;
  res = do_nbr(nbr1->len + nbr2->len + 1);
  if (do_cmp(nbr1, nbr2, info) > 0)
    do_swap(&nbr1, &nbr2);
  while ((info->var->c)++ < nbr2->len)
    {
      tmp = do_nbr(nbr1->len + nbr2->len + 1);
      info->var->d = -1;
      while ((info->var->d)++ < nbr1->len)
	do_mul2(info, nbr1, nbr2, tmp);
      res = do_add(res, tmp, info);
      do_free_nbr(tmp);
    }
  res->is_neg = res_is_neg(nbr1, nbr2);
  return (res);
}
