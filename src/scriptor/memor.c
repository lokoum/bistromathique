/*
** memor.c for bistro in /home/theis_p/bistro/src/scriptor
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct 26 15:43:46 2015 Paul THEIS
** Last update Sun Nov  1 23:09:41 2015 Paul THEIS
*/

#include "main.h"

char		*my_realloc(char *old, int size)
{
  char		*new;

  if ((new = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  my_strcpy(new, old);
  return (new);
}

unsigned int		my_getnbr_u(char *str)
{
  unsigned int		i;
  unsigned int		nbr;
  unsigned int		div;

  i = 0;
  nbr = 1;
  div = 0;
  while (str[i])
    {
      if (str[i] >= 48 && str[i] <= 57)
	{
	  while (str[i] && str[i] >= 48 && str[i] <= 57)
	    {
	      if (div > div * 10 + (str[i] - 48))
		return (0);
	      div = div * 10 + (str[i++] - 48);
	    }
	  return (div * nbr);
	}
      i++;
    }
  return (0);
}
