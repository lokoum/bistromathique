/*
** do_div.c for do_div in /home/troncy_l/prog/bistromatorNEWalgo/src/do
** 
** Made by troncy_l
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Oct 31 19:19:18 2015 troncy_l
** Last update Sun Nov  1 23:08:34 2015 troncy_l
*/

#include "main.h"

t_nbr		*div_add(t_info *info, t_nbr *res, int *loop)
{
  res->nbr[info->var->d - 1] = info->var->e % info->baselen;
  (res->len)++;
  (info->var->d)++;
  *loop = *loop - 1;
  info->var->c = 0;
  return (res);
}

t_nbr		*reinit_tmp(t_info *info, t_nbr *tmp, t_nbr *nbr1, t_nbr *nbr2)
{
  while (info->var->c <= tmp->len)
    {
      tmp->nbr[tmp->len - info->var->c] = tmp->nbr[tmp->len - info->var->c - 1];
      (info->var->c)++;
    }
  tmp->nbr[0] = nbr1->nbr[ nbr1->len - nbr2->len - info->var->d];
  (tmp->len)++;
  return (tmp);
}

t_nbr		*little_sub(t_nbr *tmp, t_nbr *nbr2, t_info *info)
{
  while (do_cmp(nbr2, tmp, 0) >= 0 && info->var->e != info->baselen)
    {
      tmp = do_sub(tmp, nbr2, info);
      tmp->len = my_strlen(do_nbr_to_str(tmp, info));
      (info->var->e)++;
    }
  return (tmp);
}

t_nbr		*init_calc(t_nbr *tmp, t_nbr *nbr1, int *count, int *index)
{
  int		size;

  size = *count;
  *count = 0;
  while (*count < size)
    {
      tmp->nbr[*count] = nbr1->nbr[*index + *count];
      *count = *count + 1;
    }
  tmp->len = *count;
  return (tmp);
}

t_nbr		*do_div2(t_nbr *nbr1, t_nbr *nbr2, t_nbr *res, t_info *info)
{
  t_nbr		*tmp;
  int		count;
  int		index;
  int		loop;

  info->var->d = 1;
  info->var->c = 0;
  tmp = do_nbr(nbr1->len);
  count = nbr2->len;
  index = nbr1->len - nbr2->len;
  tmp = init_calc(tmp, nbr1, &count, &index);
  loop = nbr1->len - nbr2->len;
  res->is_neg = div_isneg(nbr1, nbr2);
  while (loop >= 0)
    {
      info->var->e = 0;
      tmp = little_sub(tmp, nbr2, info);
      tmp = reinit_tmp(info, tmp, nbr1, nbr2);
      res = div_add(info, res, &loop);
    }
  res->nbr = div_revme(res->nbr, res);
  free(tmp);
  return (res);
}
