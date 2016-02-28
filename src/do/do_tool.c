/*
** do_tool.c for do_tool in /home/theis_p/addinf
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct 19 21:34:14 2015 Paul THEIS
** Last update Sun Nov  1 23:12:22 2015 troncy_l
*/

#include "main.h"

int			do_nbr_is_zero(t_nbr *nbr)
{
  if (nbr->len == 1 && nbr->nbr[0] == 0)
    return (1);
  return (0);
}

char			*do_it(char *nbr1, char *nbr2, t_info *info)
{
  char			*str;
  t_nbr			*res;
  t_nbr			*n1;
  t_nbr			*n2;

  if ((n1 = do_str_to_nbr(nbr1, info)) == NULL)
    return (NULL);
  if ((n2 = do_str_to_nbr(nbr2, info)) == NULL)
    return (NULL);
  res = NULL;
  res = do_add(n1, n2, info);
  str = do_nbr_to_str(res, info);
  if (res != n1 && res != NULL)
    do_free_nbr(res);
  do_free_nbr(n1);
  do_free_nbr(n2);
  return (str);
}

void			do_init(t_nbr *nbr, int len)
{
  int			i;

  i = 0;
  while (i< len + 1)
    {
      nbr->nbr[i] = 0;
      ++i;
    }
  nbr->len = 0;
  nbr->is_neg = 0;
}

t_nbr			*do_nbr(int len)
{
  t_nbr			*nbr;

  if ((nbr = malloc(sizeof(t_nbr))) == NULL)
    if (perrator(ERROR_MSG, NULL, 0) == 0)
      return (NULL);
  if ((nbr->nbr = malloc(len + 2)) == NULL)
    if (perrator(ERROR_MSG, NULL, 0) == 0)
      return (NULL);
  do_init(nbr, len);
  return (nbr);
}
