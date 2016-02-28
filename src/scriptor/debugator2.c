/*
** debugator2.c for debugator in /home/theis_p/bistromator
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Wed Oct 28 00:52:32 2015 Paul THEIS
** Last update Sun Nov  1 23:07:57 2015 Paul THEIS
*/

#include "main.h"

void		debug_putstr_ascii(char *name, char *str, int len)
{
  my_putstr("\033[31m");
  my_putstr(name);
  my_putstr("\033[0m");
  my_putstr(": ");
  my_putstr_ascii(str, len);
  my_putchar('\n');
}

void		my_putstr_ascii(char *str, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      my_putchar(str[i] + 48);
      i++;
    }
}

void		debug_putstr(char *name, char *str)
{
  my_putstr("\033[31m");
  my_putstr(name);
  my_putstr("\033[0m");
  my_putstr(": ");
  my_putstr(str);
  my_putchar('\n');
}

void		debug_put_nbr(char *name, int nbr)
{
  my_putstr("\033[31m");
  my_putstr(name);
  my_putstr("\033[0m");
  my_putstr(": ");
  my_put_nbr(nbr);
  my_putchar('\n');
}
