/*
** errator.c for errator in /home/theis_p/git/Piscine_C_infinadd
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct 20 13:22:16 2015 Paul THEIS
** Last update Sun Nov  1 23:09:06 2015 Paul THEIS
*/

#include "main.h"

int		perrator(char *msg1, char *msg2, char c)
{
  errator(msg1);
  errator(msg2);
  if (c != 0)
    {
      errator(" : ");
      errachar(c);
    }
  my_putchar('\n');
  exit (0);
}

int		errator(char *str)
{
  int		i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i])
    errachar(str[i++]);
  return (0);
}

int		errachar(char c)
{
  write(2, &c, 1);
  return (0);
}
