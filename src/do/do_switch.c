/*
** do_stnb.c for do_stnb.c in /home/theis_p/git/Piscine_C_infinadd
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct 20 14:26:38 2015 Paul THEIS
** Last update Sun Nov  1 23:05:32 2015 troncy_l
*/

#include "main.h"

char			*do_nbr_to_str(t_nbr *nbr, t_info *info)
{
  char			*str;
  int			i;

  if (nbr == NULL)
    return (0);
  if (nbr->is_neg && do_nbr_is_zero(nbr))
    nbr->is_neg = 0;
  if ((str = malloc(nbr->len + nbr->is_neg + 2)) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  if (nbr->is_neg)
    str[0] = info->struc[OP_SUB_IDX];
  i = nbr->len;
  info->var->a = 0;
  while ((--i) >= 0)
    {
      if (info->var->a || nbr->nbr[i] != 0)
        str[((++(info->var->a)) - 1) + nbr->is_neg]
	  = to_base(nbr->nbr[i], info);
    }
  if (info->var->a == 0 &&
      (str[info->var->a + nbr->is_neg] = info->base[0]) == info->base[0])
    (info->var->a)++;
  str[info->var->a + nbr->is_neg] = '\0';
  return (str);
}

t_nbr			*do_str_to_nbr(char *str, t_info *info)
{
  t_nbr			*nbr;
  int			len;
  int			i;

  len = my_strlen(str);
  i = len;
  info->var->a = 0;
  if ((nbr = do_nbr(len)) == NULL)
    return (0);
  while ((i--) > 0)
    {
      if (str[i] == info->struc[OP_SUB_IDX])
        nbr->is_neg = 1;
      else
        {
          nbr->nbr[info->var->a] = from_base(str[i], info);
          (info->var->a)++;
        }
    }
  nbr->nbr[info->var->a] = '\0';
  nbr->len = info->var->a;
  return (nbr);
}
