/*
** do_dec.c for doDec in /home/troncy_l/prog/bistroLAST/bistromator
** 
** Made by troncy_l
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Nov  1 13:46:44 2015 troncy_l
** Last update Sun Nov  1 23:10:06 2015 troncy_l
*/

#include "main.h"

int		div_cmp(t_nbr *i, t_nbr *nbr1, int end)
{
  if (i->len < nbr1->len)
    return (-1);
  else if (i->len > nbr1->len)
    {
      return (1);
    }
  else
    {
      end = i->len;
      while (--end >= 0)
	{
	  if (i->nbr[end] < nbr1->nbr[end])
	    return (-1);
	  else if (i->nbr[end] > nbr1->nbr[end])
	    {
	      return (1);
	    }
	}
      return (0);
    }
}

t_nbr		*do_div(t_nbr *nbr1, t_nbr *nbr2, t_info *info)
{
  t_nbr		*res;

  info = info;
  res = do_nbr(nbr1->len);
  if (div_cmp(nbr1, nbr2, 0) < 0)
    res->nbr[0] = 0;
  else if (div_cmp(nbr1, nbr2, 0) == 0)
    {
      res->nbr[0] = 1;
      res->len = 1;
      if (nbr1->is_neg != nbr2->is_neg)
	res->is_neg = 1;
    }
  else if (nbr2->len == 1 && nbr2->nbr[0] == 0)
    perrator(ERROR_MSG, NULL, 0);
  else
    res = do_div2(nbr1, nbr2, res, info);
  return (res);
}

t_nbr		*do_mod(t_nbr *nbr1, t_nbr *nbr2, t_info *info)
{
  t_nbr		*res;
  t_nbr		*tmp;
  int		yolo;

  yolo = nbr1->is_neg;
  res = do_nbr(nbr1->len);
  tmp = do_nbr(nbr1->len);
  nbr2->is_neg = 0;
  tmp = do_div(nbr1, nbr2, info);
  tmp = do_mul(tmp, nbr2, info);
  nbr1->is_neg = yolo;
  res = do_sub(nbr1, do_str_to_nbr(do_nbr_to_str(tmp, info), info), info);
  res->is_neg = yolo;
  return (res);
}

char		*div_revme(char *str, t_nbr *res)
{
  int		len;
  int		i;
  char		tmp;

  i = 0;
  len = res->len;
  while (i < (len - len / 2))
    {
      tmp = *(str + i);
      *(str + i) = *(str + len - 1 - i);
      *(str + len - 1 - i) = tmp;
      i++;
    }
  return (str);
}

int		div_isneg(t_nbr *nbr1, t_nbr *nbr2)
{
  int		is_neg;

  is_neg = (nbr2->is_neg != nbr1->is_neg) ? (1) : (0);
  nbr1->is_neg = 0;
  nbr2->is_neg = 0;
  return (is_neg);
}
